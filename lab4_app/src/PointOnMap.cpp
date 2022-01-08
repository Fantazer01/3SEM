//
// Created by oleg on 08.01.2022.
//

#include "PointOnMap.h"

double PointOnMap::getDistance(PointOnMap point) const
{
    return sqtr(pow(x-point.x, 2) + pow(y-point.y, 2));
}