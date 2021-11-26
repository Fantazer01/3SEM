//
// Created by oleg on 10.11.2021.
//

#include "TableOfShips.h"

namespace lab4 {

    std::ostream& TableOfShips::print(std::ostream &output) const
    {
        for (const auto &obj : cells) {
            output << "callsign" << obj.first << std::endl
                   << obj.second;
        }
        return output;
    }

    std::ostream& operator <<(std::ostream &output, const TableOfShips &table)
    {
        table.print(output);
        return output;
    }
}