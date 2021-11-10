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

void setConnectPCB(Lab3C::printedCircuitBoard &_arduino) {
    short i, n = _arduino.getCurrentNumber(), numOfContact;

    std::cout << "Numbers of input contacts: ";
    for (i = 0; i < n; ++i)
        if (_arduino[i].type == Lab3C::in)
            std::cout << i << " ";

    std::cout << "Enter number for output contact, if you want to connect it, else write \".\" and click \"Enter\"\n";
    for (i = 0; i < n; ++i) {
        if (_arduino[i].type == Lab3C::out) {
            while (1) {
                std::cout << "Output contact " << i << ": ";
                std::cin >> numOfContact;
                if (std::cin.eof() ||std::cin.bad())
                    return;
                if (std::cin.fail()) {
                    std::cout << "An error occurred while typing" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                if ((numOfContact > -1  && numOfContact < n) && _arduino[numOfContact].type == Lab3C::in && _arduino[numOfContact].numberOfContact == -1) {
                    _arduino.establishConnect(i, numOfContact);
                    break;
                } else {
                    if (numOfContact > -1  && numOfContact >= n)
                        std::cout << "Contact have this number doesn't exist\n";
                    else if (_arduino[numOfContact].type != Lab3C::in)
                        std::cout << "Contact's type isn't input\n";
                    else if (_arduino[numOfContact].numberOfContact != -1)
                        std::cout << "Contact " << numOfContact << " is busy. Try select another contact." << std::endl;
                    else {
                        std::cout << "Sorry, but something went wrong\n";
                        break;
                    }
                }
            }
        }
    }
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

void initializationPairShape(Lab3C::printedCircuitBoard &_arduino, std::vector<std::pair<sf::RectangleShape, int>> &rectangles, std::vector<std::pair<sf::CircleShape, int>> circles) {
    short i, j = 0, k = 0;
    short n = _arduino.getCurrentNumber();
    for (i = 0; i < n; ++i) {
        if (_arduino[i].type == Lab3C::out)
            rectangles[j++].second = i;
        else
            circles[k++].second = i;
    }
}



