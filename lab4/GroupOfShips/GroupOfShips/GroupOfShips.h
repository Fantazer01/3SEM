//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_GROUPOFSHIPS_H
#define LAB4_GROUPOFSHIPS_H

#include <utility>

#include "TableOfShips.h"

namespace lab4 {
    class GroupOfShips {
    private:
        TableOfShips table;
        Person commander;
        std::string from;
        std::string to;
        double distance;//Расстояние между пунктами
    public:
        GroupOfShips() = default;
        GroupOfShips(TableOfShips _table, Person _commander, double _distance)
        :table(std::move(_table)), commander(std::move(_commander)), distance(_distance) {}

        Person getCommander() const { return commander; }
        std::string getDeparturePoint() const { return from; }
        std::string getPointOfArrival() const { return to; }
        double getDistance() const { return distance; }

        void setCommander(Person _commander) { commander = std::move(_commander); }
        void setDeparturePoint(std::string _from) { from = std::move(_from); }
        void setPointOfArrival(std::string _to) { to = std::move(_to); }
        void setDistance(double _distance) { distance = _distance; }

        TableOfShips::const_iterator begin() const { return table.begin(); }
        TableOfShips::const_iterator end() const { return table.end(); }

        Ship* find(const std::string& first) const { return table.find(first); }
        void insert(const std::string& first, Ship * second) { table.insert(first, second); }
        void erase(const TableOfShips::const_iterator &out_it) { table.erase(out_it); }

        uint getNumShipOfType() const;

    };
}



#endif //LAB4_GROUPOFSHIPS_H
