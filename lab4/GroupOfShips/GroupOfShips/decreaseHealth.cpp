//
// Created by oleg on 04.01.2022.
//

#include "GroupOfShips.h"

namespace lab4
{
    void decreaseHealthTarget(Target_set &target)
    {
        for (auto &plane: target.air)
            plane.first->decreaseVitality(plane.second);
        for (auto &ship: target.earth)
            ship.first->decreaseVitality(ship.second);
    }

    void eraseDestroyedPlanesEnemy(vecPlane &enemy_aircraft)
    {
        for (auto planeIt = enemy_aircraft.begin(); planeIt != enemy_aircraft.end(); ++planeIt)
            if (planeIt->getVitality() == 0)
                enemy_aircraft.erase(planeIt);
    }

    ship_iterator findNormalAircraftCarrier(const GroupOfShips &group)
    {
        for (auto shipIt = group.begin(); shipIt != group.end(); ++shipIt)
            if (typeid(*(*shipIt).second) == typeid(AircraftCarrier) && (*(*shipIt).second).getVitality() > 0)
                return shipIt;
        return group.end();
    }

    void movingPlanesFromSinkingShip(ship_iterator shipIt_from, ship_iterator shipIt_to, GroupOfShips &group)
    {
        auto planeIt = dynamic_cast<AircraftCarrier &>(*(*shipIt_from).second).beginForPlane();
        auto planeIt_end = dynamic_cast<AircraftCarrier &>(*(*shipIt_from).second).endForPlane();
        for (; planeIt != planeIt_end; ++planeIt)
            if (planeIt->getVitality() != 0)
                group.movePlane(planeIt, shipIt_from, shipIt_to);
    }

    void eraseDestroyedPlanes(ship_iterator it)
    {
        auto planeIt = dynamic_cast<AircraftCarrier &>(*(*it).second).beginForPlane();
        auto planeIt_end = dynamic_cast<AircraftCarrier &>(*(*it).second).endForPlane();
        for (; planeIt != planeIt_end; ++planeIt)
            if (planeIt->getVitality() == 0)
                dynamic_cast<AircraftCarrier &>(*(*it).second).erasePlane(planeIt);
    }

    void eraseDestroyedMemberOfGroup(GroupOfShips &group)
    {
        auto aliveAirCar_it = findNormalAircraftCarrier(group);

        for (auto ship_it = group.begin(); ship_it != group.end(); ++ship_it) {
            if ((*ship_it).second->getVitality() == 0) {
                if (aliveAirCar_it != group.end() && typeid(*(*ship_it).second) == typeid(AircraftCarrier))
                    movingPlanesFromSinkingShip(ship_it, aliveAirCar_it, group);
                group.erase(ship_it);
            } else if (typeid(*(*ship_it).second) == typeid(AircraftCarrier)) {
                eraseDestroyedPlanes(ship_it);
            }
        }
    }

    void decreaseHealth
            (vecPlane &enemy_aircraft, GroupOfShips &group, Target_set &target_enemy, Target_set &target_group)
    {
        decreaseHealthTarget(target_enemy);
        decreaseHealthTarget(target_group);

        eraseDestroyedPlanesEnemy(enemy_aircraft);
        eraseDestroyedMemberOfGroup(group);
    }
}