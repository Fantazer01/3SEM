//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_TABLEOFSHIPS_H
#define LAB4_TABLEOFSHIPS_H

#include "../Ship/Ship.h"

class Cell {
    Ship *point;
    std::string callsign;
};

class TableOfShips {
private:
    std::vector <Cell> cells;

};


#endif //LAB4_TABLEOFSHIPS_H
