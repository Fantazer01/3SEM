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