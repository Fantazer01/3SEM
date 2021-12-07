//
// Created by oleg on 10.11.2021.
//

#include "GroupOfShips.h"

namespace lab4
{
    uint GroupOfShips::getNumShipOfType() const
    {
        return 0;
    }

    uint damage(const std::vector<Plane> &enemy_aircraft)
    {
        return 0;
    }

    uint damage(const GroupOfShips &group)
    {
        return 1;
    }

    bool IsFightOver(const std::vector<Plane> &enemy_aircraft, const GroupOfShips &group)
    {
        if (enemy_aircraft.empty())
            return true;
        if (group.getNumOfGroup() == 0)
            return true;
        if (damage(enemy_aircraft) == 0 && damage(group) == 0)
            return true;
        return false;
    }

    Target_set groupAiming(std::vector<Plane> &enemy_aircraft, GroupOfShips &group)
    {
        Target_set target;

        return target;
    }

    Target_set enemyAiming(std::vector<Plane> &enemy_aircraft, GroupOfShips &group)
    {
        Target_set target;

        return target;
    }

    void decreaseHealth
        (std::vector<Plane> &enemy_aircraft, GroupOfShips &group, Target_set &target_enemy, Target_set &target_group)
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

    ResultOfFight GroupOfShips::modeling(std::vector<Plane> enemy_aircraft) const
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