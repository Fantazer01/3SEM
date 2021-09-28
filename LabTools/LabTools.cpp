//
// Created by oleg on 28.09.2021.
//

#include <iostream>

void skip_to_int() {
    if (std::cin.fail()) {
        std::cin.clear();
        for (char ch; std::cin >> ch;) {
            if (std::isdigit(ch) || ch == '-') {
                std::cin.unget();

                return;
            }
        }
    }
    throw "Ввода нет";
}

int getNum(int &num) {
    while (true) {
        if (std::cin >> num)
            break;
        else
            skip_to_int();
    }
    return 0;
}

