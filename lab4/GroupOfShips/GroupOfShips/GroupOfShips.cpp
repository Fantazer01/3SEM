//
// Created by oleg on 10.11.2021.
//

#include "GroupOfShips.h"

namespace lab4
{
    uint GroupOfShips::getNumOfPlanes() const
    {
        uint counter = 0;
        for (auto && it : *this)
            if (typeid(*(it).second) == typeid(AircraftCarrier))
                counter += dynamic_cast<AircraftCarrier&>(*(it).second).getNumPlanes();

        return counter;
    }

    uint GroupOfShips::getNumShipOfType(const std::type_info &typeInfo) const
    {
        uint counter = 0;
        for (auto && it : *this)
            if (typeid(*(it).second) == typeInfo)
                ++counter;

        return counter;
    }

    void GroupOfShips::movePlane(plane_iterator it_plane, ship_iterator it_from, ship_iterator it_to)
    {
        if (typeid(*(*it_from).second) != typeid(AircraftCarrier))
            throw std::invalid_argument("invalid value! First iterator isn't pointing on AircraftCarrier");

        if (typeid(*(*it_to).second) != typeid(AircraftCarrier))
            throw std::invalid_argument("invalid value! Second iterator isn't pointing on AircraftCarrier");

        auto it_p = dynamic_cast<AircraftCarrier&>(*(*it_from).second).beginForPlane();
        for (; it_p != dynamic_cast<AircraftCarrier&>(*(*it_from).second).endForPlane(); ++it_p)
            if (it_p == it_plane)
            {
                dynamic_cast<AircraftCarrier&>(*(*it_to).second).addPlane(*it_p);
                dynamic_cast<AircraftCarrier&>(*(*it_from).second).erasePlane(it_p);
                return;
            }
        throw std::invalid_argument("invalid value! Plane isn't looked");
    }

    uint damage_air(const vecPlane &enemy_aircraft)
    {
        uint damage = 0;
        for (const auto & plane : enemy_aircraft)
            damage += plane.calculateDamage(air);

        return damage;
    }

    uint damage_earth(const vecPlane &enemy_aircraft)
    {
        uint damage = 0;
        for (const auto & plane : enemy_aircraft)
            damage += plane.calculateDamage(earth);

        return damage;
    }

    uint damage_air(const GroupOfShips &group)
    {
        uint damage = 0;
        for (auto it = group.begin(); it != group.end(); ++it) {
            damage += (*(*it).second).calculateDamage(air);
            if (typeid(*(*it).second) == typeid(AircraftCarrier)) {
                auto it_p = dynamic_cast<AircraftCarrier&>(*(*it).second).beginForPlane();
                for (; it_p != dynamic_cast<AircraftCarrier&>(*(*it).second).endForPlane(); ++it_p)
                    damage += it_p->calculateDamage(air);
            }
        }

        return damage;
    }

    bool IsFightOver(const vecPlane &enemy_aircraft, const GroupOfShips &group)
    {
        if (enemy_aircraft.empty())
            return true;

        if (group.getNumOfGroup() == 0)
            return true;

        bool enemy_damage_in_air_non = damage_air(enemy_aircraft) == 0 || group.getNumOfPlanes() == 0;
        bool enemy_damage_non = damage_earth(enemy_aircraft) == 0 && enemy_damage_in_air_non;

        if (enemy_damage_non && damage_air(group) == 0)
            return true;

        return false;
    }

    void step_change_target_for_group(std::list<Plane *> &enemy_aircraft, Target_set &target)
    {
        if (target.air.empty() || target.air.begin()->first->getVitality()-target.air.begin()->second <= 0)
        {
            target.air.emplace_front(std::make_pair(*enemy_aircraft.begin(), 0));
            enemy_aircraft.pop_front();
        }
    }

    void shipAiming(std::list<Plane *> &enemy_aircraft, Ship *p_ship, Target_set &target)
    {
        for (auto it = p_ship->beginForWeapon(); it != p_ship->endForWeapon(); ++it)
        {
            if (enemy_aircraft.empty())
                return;
            if (it->getType() != Weapon::light)
                continue;
            step_change_target_for_group(enemy_aircraft, target);
            target.air.begin()->second += it->getDestruction();
        }

        //for (auto & a : target.air)
        //    std::cout << "target air \n" << *(a.first) << "\ndamage: " << a.second << "\n";

        if (typeid(*p_ship) == typeid(AircraftCarrier))
        {
            auto it_p = dynamic_cast<AircraftCarrier&>(*p_ship).beginForPlane();
            for (; it_p != dynamic_cast<AircraftCarrier&>(*p_ship).endForPlane(); ++it_p)
            {
                if (enemy_aircraft.empty())
                    return;
                step_change_target_for_group(enemy_aircraft, target);
                target.air.begin()->second += it_p->calculateDamage(air);
            }
        }
    }

    Target_set groupAiming(std::list<Plane *> enemy_aircraft_pointer, GroupOfShips &group)
    {
        Target_set target;

        TableOfShips::const_iterator it;
        for (it = group.begin(); it != group.end(); ++it)
            shipAiming(enemy_aircraft_pointer, (*it).second, target);

        return target;
    }

    void step_change_target_for_enemy(GroupOfShips &group, Target_set &target)
    {
        if (target.earth.empty() || target.earth.begin()->first->getVitality() - target.earth.begin()->second <= 0)
        {
            target.earth.emplace_front((*group.begin()).second, 0);
            group.erase(group.begin());
        }

        if (target.air.empty() || target.air.begin()->first->getVitality() - target.air.begin()->second <= 0)
        {
            for (auto && it : group)
                if (typeid(*(it).second) == typeid(AircraftCarrier) && dynamic_cast<AircraftCarrier&>(*(it).second).getNumPlanes() != 0) {
                    auto it_p = dynamic_cast<AircraftCarrier&>(*(it).second).beginForPlane();
                    target.air.emplace_front(&(*it_p), 0);
                    dynamic_cast<AircraftCarrier&>(*(it).second).erasePlane(it_p);
                    break;
                }
        }
    }

    void enemy_plane_aiming(const Plane &plane, GroupOfShips &group, Target_set &target)
    {
        if (group.getNumOfGroup() != 0)
        {
            step_change_target_for_enemy(group, target);
            target.earth.begin()->second += plane.calculateDamage(earth);
            target.air.begin()->second += plane.calculateDamage(air);
        }
    }

    Target_set enemyAiming(vecPlane &enemy_aircraft, GroupOfShips group)
    {
        Target_set target;

        for (auto & it : enemy_aircraft)
            enemy_plane_aiming(it, group, target);

        return target;
    }

    void decreaseHealthEnemy(Target_set &target_enemy)
    {
        for (auto & it : target_enemy.air)
            it.first->decreaseVitality(it.second);
        for (auto & it : target_enemy.earth)
            it.first->decreaseVitality(it.second);
    }

    void decreaseHealthGroup(Target_set &target_group)
    {
        for (auto & it : target_group.air)
            it.first->decreaseVitality(it.second);
        for (auto & it : target_group.earth)
            it.first->decreaseVitality(it.second);
    }

    void eraseDestroyedPlanesEnemy(vecPlane &enemy_aircraft)
    {
        for (auto it = enemy_aircraft.begin(); it != enemy_aircraft.end(); ++it)
            if (it->getVitality() == 0)
                enemy_aircraft.erase(it);
    }

    ship_iterator findNormalAircraftCarrier(const GroupOfShips &group)
    {
        for (auto it = group.begin(); it != group.end(); ++it)
            if (typeid(*(*it).second) == typeid(AircraftCarrier) && (*(*it).second).getVitality() > 0)
                return it;
        return group.end();
    }

    void movingPlanesFromSinkingShip(ship_iterator it_from, ship_iterator it_to, GroupOfShips &group)
    {
        auto it_p = dynamic_cast<AircraftCarrier&>(*(*it_from).second).beginForPlane();
        for (; it_p != dynamic_cast<AircraftCarrier&>(*(*it_from).second).endForPlane(); ++it_p)
            if (it_p->getVitality() != 0)
                group.movePlane(it_p, it_from, it_to);
    }

    void eraseDestroyedPlanes(ship_iterator it)
    {
        auto it_p = dynamic_cast<AircraftCarrier&>(*(*it).second).beginForPlane();
        for (; it_p != dynamic_cast<AircraftCarrier&>(*(*it).second).endForPlane(); ++it_p)
            if (it_p->getVitality() == 0)
                dynamic_cast<AircraftCarrier&>(*(*it).second).erasePlane(it_p);
    }

    void eraseDestroyedMemberOfGroup(GroupOfShips &group)
    {
        auto it_to = findNormalAircraftCarrier(group);

        for (auto it = group.begin(); it != group.end(); ++it)
        {
            if ((*it).second->getVitality() == 0)
            {
                if (it_to != group.end() && typeid(*(*it).second) == typeid(AircraftCarrier))
                    movingPlanesFromSinkingShip(it, it_to, group);
                group.erase(it);
            } else if (typeid(*(*it).second) == typeid(AircraftCarrier))
            {
                eraseDestroyedPlanes(it);
            }
        }
    }

    void decreaseHealth
        (vecPlane &enemy_aircraft, GroupOfShips &group, Target_set &target_enemy, Target_set &target_group)
    {
        decreaseHealthEnemy(target_enemy);

        decreaseHealthGroup(target_group);

        eraseDestroyedPlanesEnemy(enemy_aircraft);
        eraseDestroyedMemberOfGroup(group);

    }

    ResultOfFight GroupOfShips::modeling(vecPlane enemy_aircraft) const
    {
        GroupOfShips copy_group(*this);

        while (IsFightOver(enemy_aircraft, copy_group))
        {
            copy_group.stepOfFight(enemy_aircraft);
        }

        if (copy_group.getNumOfGroup() == 0)
            return fail;
        if (enemy_aircraft.empty())
            return win;
        return fight_over;
    }

    std::list<Plane *> createPointerList(vecPlane &enemy_aircraft)
    {
        std::list<Plane *> enemy_aircraft_pointer(enemy_aircraft.size());
        auto it = enemy_aircraft.begin();
        auto it_p = enemy_aircraft_pointer.begin();
        for (; it != enemy_aircraft.end(); ++it, ++it_p)
            *it_p = &(*it);
        return enemy_aircraft_pointer;
    }

    void GroupOfShips::stepOfFight(vecPlane &enemy_aircraft) {
        std::list<Plane *> enemy_aircraft_pointer;
        enemy_aircraft_pointer = createPointerList(enemy_aircraft);

        // 1. Прицелилась группа
        Target_set target_group = groupAiming(enemy_aircraft_pointer, *this);
        /*// 2. Прицелились вражеские самолеты
        Target_set target_enemy = enemyAiming(enemy_aircraft, *this);
        // 3. Убавили здоровье всех участников боя, исключили тех, чье здоровье равно нулю
        decreaseHealth(enemy_aircraft, *this, target_enemy, target_group);*/
    }
}