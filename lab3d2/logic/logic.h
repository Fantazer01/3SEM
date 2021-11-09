//
// Created by oleg on 05.11.2021.
//

#include "Printed_Circuit_Board.h"

#ifndef LAB3D2_LOGIC_H
#define LAB3D2_LOGIC_H

void FillPCB(Lab3C::printedCircuitBoard &arduino, int input, int output);
void initializationPCB(Lab3C::printedCircuitBoard &_arduino);
int getInput(Lab3C::printedCircuitBoard &_arduino);
int getOutput(Lab3C::printedCircuitBoard &_arduino);

#endif //LAB3D2_LOGIC_H
