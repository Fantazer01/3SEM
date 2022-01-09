//
// Created by oleg on 09.01.2022.
//

#include "Port.h"

ship_iterator Port::find(const std::string &callSign) const
{
    return groupInsidePort.find(callSign);
}

void Port::insert(const std::string& first, Ship * second)
{
    groupInsidePort.insert(first, second);
}

void Port::erase(const ship_iterator &out_it)
{
    groupInsidePort.erase(out_it);
}

std::ostream& Port::print(std::ostream &output) const
{
    output << "Port: " << this->getName() << std::endl;

    std::string beginChar = "  ";
    ship_iterator shipIt = groupInsidePort.begin();

    output << "Ships:" << std::endl;
    if (shipIt == groupInsidePort.end())
    {
        output << "Empty!" << std::endl;
        return output;
    }

    for (; shipIt != groupInsidePort.end(); ++shipIt)
    {
        output << beginChar << "Call sign: " << shipIt->first << std::endl;
        shipIt->second->print(output, beginChar);
        output << std::endl;
    }
    return output;
}