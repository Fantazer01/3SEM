//
// Created by oleg on 05.11.2021.
//

#include "Printed_Circuit_Board.h"
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#ifndef LAB3D2_LOGIC_H
#define LAB3D2_LOGIC_H

void FillPCB(Lab3C::printedCircuitBoard &arduino, int input, int output);
void initializationPCB(Lab3C::printedCircuitBoard &_arduino);
void setConnectPCB(Lab3C::printedCircuitBoard &_arduino);
int getInput(Lab3C::printedCircuitBoard &_arduino);
int getOutput(Lab3C::printedCircuitBoard &_arduino);

void initializationPairShape(Lab3C::printedCircuitBoard &_arduino, std::vector<std::pair<sf::RectangleShape, int>> &rectangles, std::vector<std::pair<sf::CircleShape, int>> circles);

#endif //LAB3D2_LOGIC_H
