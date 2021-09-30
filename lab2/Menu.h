//
// Created by oleg on 29.09.2021.
//
#include "LineCassini.h"

#ifndef LAB2_MENU_H
#define LAB2_MENU_H

int dialog(const char **, int );

int getA(LineCassini &);

int getC(LineCassini &);

int distFromOrigin(LineCassini &);

int setA(LineCassini &);

int setC(LineCassini &);

int setAC(LineCassini &);

int formLine(LineCassini &);

int radiusOfCurvature(LineCassini &);

int inflectionPointCoordinates(LineCassini &);

int equationOfLine(LineCassini &);

#endif //LAB2_MENU_H
