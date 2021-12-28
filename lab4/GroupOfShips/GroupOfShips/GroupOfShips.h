//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_GROUPOFSHIPS_H
#define LAB4_GROUPOFSHIPS_H

#include <utility>
#include <list>

#include "TableOfShips.h"
#include "AircraftCarrier.h"
#include "Destroyer.h"

namespace lab4 {

    typedef TableOfShips::const_iterator ship_iterator;
    typedef vecPlane::const_iterator plane_iterator;

    enum ResultOfFight {
        win,
        fight_over,
        fail
    };

    /*!
     * Target_set tells us who and how many damage got during one step of fight
     */
    struct Target_set {
        std::list<std::pair<Plane *, uint>> air;
        std::list<std::pair<Ship *, uint>> earth;
    };

    /*!
     * GroupOfShip is main class - container, combines a set of ships and planes into one whole
     */
    class GroupOfShips {
    private:
        TableOfShips table;
        Person commander;
        std::string from;
        std::string to;
        double distance{};
    public:
        GroupOfShips() = default;
        GroupOfShips(const TableOfShips& _table, Person _commander, std::string _from, std::string _to, double _distance)
        :table(_table), commander(std::move(_commander)), from(std::move(_from)), to(std::move(_to)), distance(_distance) {}

        TableOfShips getTable() const { return table; }
        Person getCommander() const { return commander; }
        std::string getDeparturePoint() const { return from; }
        std::string getPointOfArrival() const { return to; }
        double getDistance() const { return distance; }
        uint getNumOfGroup() const { return table.getNumOfGroup(); }
        uint getNumOfPlanes() const;

        void setTable(const TableOfShips& _table) { table = _table; }
        void setCommander(Person _commander) { commander = std::move(_commander); }
        void setDeparturePoint(std::string _from) { from = std::move(_from); }
        void setPointOfArrival(std::string _to) { to = std::move(_to); }
        void setDistance(double _distance) { distance = _distance; }

        TableOfShips::const_iterator begin() const { return table.begin(); }
        TableOfShips::const_iterator end() const { return table.end(); }

        TableOfShips::const_iterator find(const std::string& first) const { return table.find(first); }
        void insert(const std::string& first, Ship * second) { table.insert(first, second); }
        void erase(const TableOfShips::const_iterator &out_it) { table.erase(out_it); }

        uint getNumShipOfType(const std::type_info &typeInfo) const;

        void movePlane(plane_iterator it_plane, ship_iterator it_from, ship_iterator it_to);

        ResultOfFight modeling(vecPlane enemy_aircraft) const;

    };
}



#endif //LAB4_GROUPOFSHIPS_H
