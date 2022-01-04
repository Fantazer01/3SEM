//
// Created by oleg on 03.01.2022.
//

#include "GroupOfShips.h"

namespace lab4
{
    void step_change_target_for_enemy(Target_set &target, Target_plane_it planeIt, Target_ship_it shipIt) {
        if (target.earth.empty() || (shipIt->first->getVitality() - shipIt->second) <= 0)
            ++shipIt;

        if (target.air.empty() || (planeIt->first->getVitality() - planeIt->second) <= 0)
            ++planeIt;
    }

    void enemy_plane_aiming(vecPlane::iterator enemyIt, Target_set &target, Target_plane_it planeIt, Target_ship_it shipIt)
    {
        step_change_target_for_enemy(target, planeIt, shipIt);
        target.earth.begin()->second += enemyIt->calculateDamage(earth);
        target.air.begin()->second += enemyIt->calculateDamage(air);
    }

    void enemyAiming(Target_set &target, vecPlane &enemy_aircraft) {
        Target_plane_it planeIt = target.air.begin();
        Target_ship_it shipIt = target.earth.begin();
        auto enemyIt = enemy_aircraft.begin();
        for (; enemyIt != enemy_aircraft.end(); ++enemyIt) {
            if (planeIt == target.air.end() && shipIt == target.earth.end())
                return;
            enemy_plane_aiming(enemyIt, target, planeIt, shipIt);
        }

    }
}