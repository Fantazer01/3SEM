//
// Created by oleg on 12.11.2021.
//

#include "Destroyer.h"

namespace lab4 {

    std::ostream& Destroyer::print(std::ostream &output) const
    {
        int i = 1;
        this->Ship::print(output);
        output << "covered ship: ";
        if (covered == nullptr)
            output << "no info" << std::endl;
        else
            output << covered->getName() << std::endl;

        return output;
    }

    std::ostream& operator <<(std::ostream &output, Destroyer &ship)
    {
        ship.print(output);
        return output;
    }

}