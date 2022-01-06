//
// Created by oleg on 10.11.2021.
//

#include "TableOfShips.h"

namespace lab4 {

    TableOfShips::TableOfShips(const TableOfShips &table)
    {
        for(auto && item : table)
        {
            (*this).cells.insert(std::make_pair(item.first, item.second->clone()));
        }
    }

    TableOfShips::~TableOfShips()
    {
        for(auto && item : cells)
        {
            delete item.second;
            item.second = nullptr;
        }
    }

    TableOfShips& TableOfShips::operator = (const TableOfShips &table)
    {
        for(auto && item : cells)
        {
            delete item.second;
            item.second = nullptr;
        }
        cells.clear();
        for(auto && item : table)
        {
            (*this).cells.insert(std::make_pair(item.first, item.second->clone()));
        }
        return (*this);
    }

    void TableOfShips::insert(const std::string& first, Ship * second)
    {
        cells.insert(std::make_pair(first, second->clone()));
    }

    void TableOfShips::erase(const const_iterator &out_it)
    {
        delete (*out_it).second;
        cells.erase(out_it.it);
    }

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