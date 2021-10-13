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

int addToStack(lab3::Stack &stack) {
    stack.read(std::cin);
    return 1;
}

int getFromStack(lab3::Stack &stack) {
    stack.print(std::cout);
    return 1;
}

int Push(lab3::Stack &stack) {
    int a;
    char s[81];
    std::cout << "Enter number" << std::endl;
    getNum(a);
    std::cout << "Enter string" << std::endl;
    std::cin >> s;
    lab3::Data data(a, s);

    stack.push(data);

    return 1;
}

int Pop(lab3::Stack &stack) {
    lab3::Data data = stack.pop();

    std::cout << "Data element:" << std::endl;
    std::cout << data.a << " " << data.s << std::endl;

    return 1;
}

