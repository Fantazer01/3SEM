//
// Created by oleg on 05.11.2021.
//
#include "logic.h"

void FillPCB(Lab3C::printedCircuitBoard &arduino, int input, int output) {
    int i;

    for(i = 0; i < output; ++i)
        arduino += Lab3C::printedCircuitBoard::Contact(static_cast<Lab3C::contactType>(1), i, 0);

    for(i = 0; i < input; ++i)
        arduino += Lab3C::printedCircuitBoard::Contact(static_cast<Lab3C::contactType>(0), i, 1);
}

void initializationPCB(Lab3C::printedCircuitBoard &_arduino) {
    int numberOfInput = 5;
    int numberOfOutput = 5;
    FillPCB(_arduino, numberOfInput, numberOfOutput);
}

int getInput(Lab3C::printedCircuitBoard &_arduino) {
    int counter = 0, n = _arduino.getCurrentNumber();
    for (int i = 0; i < n; ++i)
        if (_arduino[i].type == Lab3C::in)
            ++counter;
    return counter;
}

int getOutput(Lab3C::printedCircuitBoard &_arduino) {
    int counter = 0, n = _arduino.getCurrentNumber();
    for (int i = 0; i < n; ++i)
        if (_arduino[i].type == Lab3C::out)
            ++counter;
    return counter;
}

void initializationPairShape(Lab3C::printedCircuitBoard &_arduino, std::vector<std::pair<sf::RectangleShape, int>> &rectangles) {
    short i, j = 0;
    short n = _arduino.getCurrentNumber();
    for (i = 0; i < n; ++i) {
        if (_arduino[i].type == Lab3C::out)
            rectangles[j++].second = i;

    }
}



