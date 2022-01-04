//
// Created by oleg on 03.01.2022.
//

#include "GroupOfShips.h"

namespace lab4
{
    void step_change_target_for_group(Target_set &target, Target_plane_it &planeIt) {
        if (target.air.empty() || (planeIt->first->getVitality() - planeIt->second) <= 0)
            ++planeIt;
    }

    void PlanesOfAircraftCarrierAiming(Ship *p_ship, Target_set &target, Target_plane_it &planeIt) {
        auto it_p = dynamic_cast<AircraftCarrier &>(*p_ship).beginForPlane();
        auto it_p_end = dynamic_cast<AircraftCarrier &>(*p_ship).endForPlane();
        for (; it_p != it_p_end; ++it_p) {
            if (planeIt == target.air.end())
                return;
            step_change_target_for_group(target, planeIt);
            target.air.begin()->second += it_p->calculateDamage(air);
        }
    }

    void shipAiming(Ship *p_ship, Target_set &target, Target_plane_it &planeIt)
    {
        for (auto weaponIt = p_ship->beginForWeapon(); weaponIt != p_ship->endForWeapon(); ++weaponIt) {
            if (planeIt == target.air.end())
                return;
            if (weaponIt->getType() != Weapon::light)
                continue;
            step_change_target_for_group(target, planeIt);
            planeIt->second += weaponIt->getDestruction();
        }

        if (typeid(*p_ship) == typeid(AircraftCarrier))
            PlanesOfAircraftCarrierAiming(p_ship, target, planeIt);
    }

    void groupAiming(Target_set &target, GroupOfShips &group)
    {
        Target_plane_it planeIt = target.air.begin();
        TableOfShips::const_iterator it;
        for (it = group.begin(); it != group.end(); ++it)
            shipAiming((*it).second, target, planeIt);

    }
}
