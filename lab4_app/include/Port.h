//
// Created by oleg on 09.01.2022.
//

#ifndef LAB4_APP_PORT_H
#define LAB4_APP_PORT_H

#include <utility>

#include "PointOnMap.h"
#include "GroupOfShips.h"

using namespace lab4;

class Port : public PointOnMap {
private:
    GroupOfShips groupInsidePort;
public:
    Port() = default;
    Port(const std::string &name, double x, double y, GroupOfShips group=GroupOfShips())
            : PointOnMap(name, x, y), groupInsidePort(std::move(group)) {}

    GroupOfShips getGroup() const { return groupInsidePort; }
    void setGroup(GroupOfShips group) { groupInsidePort = std::move(group); }

    ship_iterator find(const std::string &callSign) const;
    void insert(const std::string& first, Ship * second);
    void erase(const ship_iterator &out_it);

    ship_iterator begin() const { return groupInsidePort.begin(); }
    ship_iterator end() const { return groupInsidePort.end(); }

    std::ostream& print(std::ostream &output) const;
};


#endif //LAB4_APP_PORT_H
