//
// Created by oleg on 08.01.2022.
//

#ifndef LAB4_APP_GAMEPROCESS_H
#define LAB4_APP_GAMEPROCESS_H

#include "GroupOfShips.h"
#include "PointOnMap.h"

void PutInformation(const lab4::GroupOfShips &group, const PointOnMap &placeOfLocated);
void game_process(const std::vector<PointOnMap> &points, lab4::GroupOfShips &group, const PointOnMap &startPoint);

#endif //LAB4_APP_GAMEPROCESS_H
