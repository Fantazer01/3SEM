//
// Created by oleg on 08.01.2022.
//

#include "GameProcess.h"
#include "GroupOfShips.h"
#include "PointOnMap.h"

using namespace lab4;

void PutInformation(const GroupOfShips &group, const PointOnMap &location)
{
    std::cout << "Group is located in port: " << location.getName()
              << ", coordinates: (" << location.get1stCoordinate() << ", " << location.get2ndCoordinate() << ")"<< std::endl
              << "~~~~~~~~~~~~~~~~~~~~~~Composition-of-the-group~~~~~~~~~~~~~~~~~~~~~~" << std::endl
              << group << std::endl;
}