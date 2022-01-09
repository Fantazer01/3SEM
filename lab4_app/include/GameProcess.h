//
// Created by oleg on 08.01.2022.
//

#ifndef LAB4_APP_GAMEPROCESS_H
#define LAB4_APP_GAMEPROCESS_H

#include "GroupOfShips.h"
#include "PointOnMap.h"
#include "Port.h"
#include "LabTools.h"

uint dialog(const uint &numOfStations);
void SetCompound(GroupOfShips &group, const Port &);
uint SelectPoint(const std::vector<Port> &points, lab4::GroupOfShips &group);
void PutInformation(const lab4::GroupOfShips &group);
void game_process(const std::vector<Port> &points, lab4::GroupOfShips &group, const Port &startPoint);

#endif //LAB4_APP_GAMEPROCESS_H
