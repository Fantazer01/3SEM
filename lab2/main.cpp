#include <iostream>
#include "LineCassini.h"
#include "Menu.h"

int main() {
    const char *msgs[] = {"Quit", "Get A", "Get C", "Get distanse from origin to a given point", "Set A", "Set C", "Set A&C", "Form the line", "Радиус кривизны", "вернуть координаты точек перегиба", "текстовое представление уравнения линии"};
    const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
    int (*fptr[NMsgs])(LineCassini &) = {nullptr, getA, getC, distFromOrigin, setA, setC, setAC, formLine};
    LineCassini line;
    int rc = 0;

    std::cout << "Hello, dear user!" << std::endl;

    while ((rc = dialog(msgs, NMsgs))) {
        if (!fptr[rc](line))
            break;
        std::cout<< "Что-то делаем\n";
        std::cin.get();
        std::cin.get();
        system("clear");
    }
    std::cout << "Game over" << std::endl;

    return 0;
}
