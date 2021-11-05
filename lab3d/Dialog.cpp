//
// Created by oleg on 04.11.2021.
//

#include <iostream>
#include "Dialog.h"
#include "LabTools.h"

namespace lab3d {

    void introduction() {
        std::cout << "                  $$$$\n"
                     "                 $$$$$$$\n"
                     "                 $$$$$$$$    $_$_$\n"
                     "                  $$$$$$$   $$$$$$\n"
                     "                   $$$$$     $$$\n"
                     "                     $$$$$$$$$$\n"
                     "           $___$_$    $$$$$$$\n"
                     "            $$$$$$   $$$$$$$\n"
                     "             $$$ $$$$$$$$$$$$\n"
                     "                      $$$$$$$$\n"
                     "                      $$$$$$$$\n"
                     "                       $$$$$$$$$$$$\n"
                     "                    $$$$$$$$$$   $$$\n"
                     "                    $$$$  $$$$$   $$$$\n"
                     "                    $$$    $$$$$  $ $ $\n"
                     "                   $ $ $   $$$$$\n"
                     "                            $$$$\n"
                     "                   $$$$$    $$$\n"
                     "                  $$   $$   $$$\n"
                     "                 $$        $$$\n"
                     "                  $$$    $$$\n"
                     "                     $$$$\n";
        std::cout << "\n                    GEEK_ON\n\n\n"
                     "                   Click ENTER\n";
        std::cin.get();
    }

    int menu() {
        const char *menu_msgs[] =
                {
                        "1. Добавить контакт",
                        "2. Установить связь между контактами",
                        "3. Вывести результат на экран",
                        "4. Выделить группу контактов заданного типа",
                        "5. Оценить длину трассы между контактами",
                        "0. Выход"
                };

        const int size_menu_msgs = sizeof(menu_msgs) / sizeof(*menu_msgs);

        for(auto & menu_msg : menu_msgs)
            std::cout << menu_msg << std::endl;

        return size_menu_msgs;
    }

    int dialog() {
        int numOfStations, rc;

        numOfStations = menu();

        do {
            try{
                getNum(rc);
            } catch (const char err[]) {
                std::cout << "End of file" << std::endl;
                return 0;
            }
        } while(rc > numOfStations || rc < 0);

        return rc;
    }

    void AddContact(Lab3C::printedCircuitBoard &_arduino) {
        Lab3C::printedCircuitBoard::Contact contact;

        std::cout << "Enter info about contact:\n"
                     "its type: 0(in) or 1(out),\n"
                     "coordinate x,\n"
                     "coordinate y\n";
        try {
            std::cin >> contact;
        } catch (std::invalid_argument err) {
            std::cout << err.what() << std::endl
                      << "Action canceled" << std::endl;
        }

        _arduino += contact;
    }

    void EstablishConnect(Lab3C::printedCircuitBoard &_arduino) {
        int num1, num2, number;
        number = _arduino.getCurrentNumber();

        std::cout << "Enter two indexes of contacts, one of they should be input, another of they should be output\n";

        std::cout << "Enter the first index: ";
        getNum(num1);
        if (num1 >= number || num1 < 0) {std::cout << "Не корректное значение" << std::endl;return;}

        std::cout << "Enter the second index: ";
        getNum(num2);
        if (num2 >= number || num2 < 0) {std::cout << "Не корректное значение! Не существует такого элемента" << std::endl;return;}
        if (num1 == num2) {std::cout << "Не корректное значение! Индексы одинаковые" << std::endl;}

        try {
            _arduino.establishConnect(num1, num2);
        } catch(std::invalid_argument err) {
            std::cout << err.what() << std::endl
                      << "Action canceled" << std::endl;
        }
    }
/*
    void RemoveContact(Lab3C::printedCircuitBoard &_arduino) {
        int num1, number;
        number = _arduino.getCurrentNumber();

        std::cout << "Enter index of contact, цршср\n";

        std::cout << "Enter the number of index: ";
        getNum(num1);
        if (num1 >= number || num1 < 0) {std::cout << "Не корректное значение" << std::endl;return;}

        std::cout << "3. что-то делаю\n";
    }
*/
    void GroupOfContacts(Lab3C::printedCircuitBoard &_arduino) {
        int t;

        std::cout << "Enter 0(input) or 1(output) type of contacts: ";
        getNum(t);
        std::cout << _arduino.groupOfContacts(t);
    }

    void LengthOfTrack(Lab3C::printedCircuitBoard &_arduino) {
        int num1, num2, number;
        number = _arduino.getCurrentNumber();

        std::cout << "Enter two indexes of contacts, one of they should be input, another of they should be output and be connection with the first\n";

        std::cout << "Enter the first index: ";
        getNum(num1);
        if (num1 >= number || num1 < 0) {std::cout << "Не корректное значение" << std::endl;return;}

        std::cout << "Enter the second index: ";
        getNum(num2);
        if (num2 >= number || num2 < 0) {std::cout << "Не корректное значение! Не существует такого элемента" << std::endl;return;}
        if (num1 == num2) {std::cout << "Не корректное значение! Индексы одинаковые" << std::endl;}
        std::cout << "5. что-то делаю\n";
    }

    void OutputPCB(Lab3C::printedCircuitBoard &_arduino) {
        std::cout << _arduino;
    }

}

