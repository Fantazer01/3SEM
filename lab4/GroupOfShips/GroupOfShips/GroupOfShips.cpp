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

    void GroupOfShips::movePlane(plane_iterator it_plane, ship_iterator shipIt_from, ship_iterator shipIt_to)
    {
        if (typeid(*(*shipIt_from).second) != typeid(AircraftCarrier))
            throw std::invalid_argument("invalid value! First iterator isn't pointing on AircraftCarrier");

        if (typeid(*(*shipIt_to).second) != typeid(AircraftCarrier))
            throw std::invalid_argument("invalid value! Second iterator isn't pointing on AircraftCarrier");

        auto planeIt = dynamic_cast<AircraftCarrier&>(*(*shipIt_from).second).beginForPlane();
        auto planeIt_end = dynamic_cast<AircraftCarrier&>(*(*shipIt_from).second).endForPlane();
        for (; planeIt != planeIt_end; ++planeIt)
            if (planeIt == it_plane)
            {
                dynamic_cast<AircraftCarrier&>(*(*shipIt_to).second).addPlane(*planeIt);
                dynamic_cast<AircraftCarrier&>(*(*shipIt_from).second).erasePlane(planeIt);
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

    Target_set createTarget(vecPlane &enemy_aircraft)
    {
        Target_set target;
        target.air.resize(enemy_aircraft.size());

        auto it = enemy_aircraft.begin();
        auto it_p = target.air.begin();
        for (; it != enemy_aircraft.end(); ++it, ++it_p) {
            it_p->first = &(*it);
            it_p->second = 0;
        }
        return target;
    }

    Target_set createTarget(GroupOfShips &group)
    {
        Target_set target;
        target.earth.resize(group.getNumOfGroup());

        auto it_group_ship = group.begin();
        auto it_tar_ship = target.earth.begin();

        for (; it_group_ship != group.end(); ++it_group_ship, ++it_tar_ship) {
            it_tar_ship->first = (*it_group_ship).second;
            it_tar_ship->second = 0;
            if (typeid(*it_tar_ship->first) == typeid(AircraftCarrier))
            {
                auto it_group_plane = dynamic_cast<AircraftCarrier &>(*it_tar_ship->first).beginForPlane();
                auto it_group_plane_end = dynamic_cast<AircraftCarrier &>(*it_tar_ship->first).endForPlane();

                for (; it_group_plane != it_group_plane_end; ++it_group_plane)
                    target.air.emplace_back(&(*it_group_plane), 0);
            }
        }

        return target;
    }

    void GroupOfShips::stepOfFight(vecPlane &enemy_aircraft) {
        Target_set target_group = createTarget(enemy_aircraft);
        Target_set target_enemy = createTarget(*this);

        // 1. Прицелилась группа
        groupAiming(target_group, *this);
        // 2. Прицелились вражеские самолеты
        enemyAiming(target_enemy, enemy_aircraft);
        // 3. Убавили здоровье всех участников боя, исключили тех, чье здоровье равно нулю
        decreaseHealth(enemy_aircraft, *this, target_enemy, target_group);
    }
}