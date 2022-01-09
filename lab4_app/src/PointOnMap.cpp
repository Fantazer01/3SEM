//
// Created by oleg on 08.01.2022.
//

#include "PointOnMap.h"
#include <cmath>

double PointOnMap::getDistance(PointOnMap point) const
{
    return sqrt(pow(x-point.x, 2) + pow(y-point.y, 2));
}