//
// Created by oleg on 08.01.2022.
//

#ifndef LAB4_APP_INITIALIZE_H
#define LAB4_APP_INITIALIZE_H

#include <vector>
#include "PointOnMap.h"
#include "Port.h"
#include "GroupOfShips.h"

std::vector<PointOnMap> initializePoints();

std::vector<Port> initializePorts();

lab4::GroupOfShips initializeGroup();

#endif //LAB4_APP_INITIALIZE_H
