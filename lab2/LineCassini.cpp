//
// Created by oleg on 29.09.2021.
//

#include "LineCassini.h"

double distFromOrigin(double angle) {

    return 0;
}

LineCassini& LineCassini::setA(double a) {
    if (a < 0)
        throw -1;
    LineCassini::a = a;
    return *this;
}

LineCassini& LineCassini::setC(double c) {
    if (c < 0)
        throw -1;
    LineCassini::c = c;
    return *this;
}

LineCassini& LineCassini::setAC(double a, double c) {
    (*this).setA(a);
    (*this).setC(c);
    return *this;
}
