//
// Created by oleg on 10.11.2021.
//

#include "GroupOfShips.h"

namespace lab4
{
    uint GroupOfShips::getNumOfPlanes() const
    {
        uint counter = 0;
        for (auto it = (*this).begin(); it != (*this).end(); ++it)
            if (typeid(*(*it).second) == typeid(AircraftCarrier))
                counter += dynamic_cast<AircraftCarrier&>(*(*it).second).getNumPlanes();

        return counter;
    }

    uint GroupOfShips::getNumShipOfType(const std::type_info &typeInfo) const
    {
        uint counter = 0;
        for (auto it = (*this).begin(); it != (*this).end(); ++it)
            if (typeid(*(*it).second) == typeInfo)
                ++counter;

        return counter;
    }

    void movePlane(plane_iterator it_plane, ship_iterator it_from, ship_iterator it_to)
    {
        if (typeid(*(*it_from).second) == typeid(AircraftCarrier))
            throw std::invalid_argument("invalid value!");

        if (typeid(*(*it_to).second) == typeid(AircraftCarrier))
            throw std::invalid_argument("invalid value!");

        auto it_p = dynamic_cast<AircraftCarrier&>(*(*it_from).second).beginForPlane();
        for (; it_p != dynamic_cast<AircraftCarrier&>(*(*it_from).second).endForPlane(); ++it_p)
            if (it_p == it_plane)
            {
                dynamic_cast<AircraftCarrier&>(*(*it_to).second).addPlane(*it_p);
                dynamic_cast<AircraftCarrier&>(*(*it_from).second).erasePlane(it_p);
                return;
            }
        throw std::invalid_argument("invalid value!");
    }

    uint damage_air(const vecPlane &enemy_aircraft)
    {
        uint damage = 0;
        for (auto it = enemy_aircraft.begin(); it != enemy_aircraft.end(); ++it)
            damage += it->calculateDamage(air);

        return damage;
    }

    uint damage_earth(const vecPlane &enemy_aircraft)
    {
        uint damage = 0;
        for (auto it = enemy_aircraft.begin(); it != enemy_aircraft.end(); ++it)
            damage += it->calculateDamage(earth);

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

    Target_set groupAiming(vecPlane &enemy_aircraft, GroupOfShips &group)
    {
        Target_set target;

        return target;
    }

    Target_set enemyAiming(vecPlane &enemy_aircraft, GroupOfShips &group)
    {
        Target_set target;

        return target;
    }

    void decreaseHealth
        (vecPlane &enemy_aircraft, GroupOfShips &group, Target_set &target_enemy, Target_set &target_group)
    {
        for (auto it = target_enemy.air.begin(); it != target_enemy.air.end(); ++it)
            it->first->decreaseVitality(it->second);
        for (auto it = target_enemy.earth.begin(); it != target_enemy.earth.end(); ++it)
            it->first->decreaseVitality(it->second);

        for (auto it = target_group.air.begin(); it != target_group.air.end(); ++it)
            it->first->decreaseVitality(it->second);
        for (auto it = target_group.earth.begin(); it != target_group.earth.end(); ++it)
            it->first->decreaseVitality(it->second);

        for (auto it = enemy_aircraft.begin(); it != enemy_aircraft.end(); ++it)
            if (it->getVitality() == 0)
                enemy_aircraft.erase(it);

        for (auto it = group.begin(); it != group.end(); ++it)
            if ((*it).second->getVitality() == 0)
                group.erase(it);

        for (auto it = group.begin(); it != group.end(); ++it) {
            if (typeid(*(*it).second) == typeid(AircraftCarrier)) {
                auto it_p = dynamic_cast<AircraftCarrier&>(*(*it).second).beginForPlane();
                for (; it_p != dynamic_cast<AircraftCarrier&>(*(*it).second).endForPlane(); ++it_p)
                    if (it_p->getVitality() == 0)
                        dynamic_cast<AircraftCarrier&>(*(*it).second).erasePlane(it_p);
            }
        }


    }

    ResultOfFight GroupOfShips::modeling(vecPlane enemy_aircraft) const
    {
        GroupOfShips copy_group(*this);

        while (IsFightOver(enemy_aircraft, copy_group))
        {
            // 1. Прицелилась группа
            Target_set target_group = groupAiming(enemy_aircraft, copy_group);
            // 2. Прицелились вражеские самолеты
            Target_set target_enemy = enemyAiming(enemy_aircraft, copy_group);
            // 3. Убавили здоровье всех участников боя, исключили тех, чье здоровье равно нулю
            decreaseHealth(enemy_aircraft, copy_group, target_enemy, target_group);//-готово
            break;
        }

        if (copy_group.getNumOfGroup() == 0)
            return fail;
        if (enemy_aircraft.empty())
            return win;
        return fight_over;
    }
}