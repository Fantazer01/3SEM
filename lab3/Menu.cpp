//
// Created by oleg on 29.09.2021.
//
#include <iostream>
#include <cstring>
#include "../LabTools/LabTools.h"
#include "Menu.h"

int dialog(const char **msgs, int NMsgs) {
    int i, a = 0;
    for (i = 0; i < NMsgs; ++i)
        std::cout << i << ". " << msgs[i] << std::endl;
    char err[10] = "";
    do {
        std::cout << err << std::endl;
        strcpy(err, "Try again");
        try {
            getNum(a);
        } catch (const char* str) {
            std::cout << "EOF" << std::endl;
            return 0;
        }
    } while (a < 0 || a >= NMsgs);
    system("clear");
    return a;
}

