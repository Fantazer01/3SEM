//
// Created by oleg on 29.09.2021.
//
#include <iostream>
#include "../LabTools/LabTools.h"
#include "Menu.h"

int dialog(const char **msgs, int NMsgs) {
    int i, a = 0;
    for (i = 0; i < NMsgs; ++i)
        std::cout << i << ". " << msgs[i] << std::endl;
    getNum(a);
    return a;
}

int getA(LineCassini &) {
    return 1;
}

int getC(LineCassini &) {
    return 1;
}

int distFromOrigin(LineCassini &) {
    return 1;
}

int setA(LineCassini &) {
    return 1;
}

int setC(LineCassini &) {
    return 1;
}

int setAC(LineCassini &) {
    return 1;
}
