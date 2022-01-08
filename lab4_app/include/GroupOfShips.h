//
// Created by oleg on 10.11.2021.
//

/*!
 * @file
 * @brief Description for class GroupOfShips
 */

#ifndef LAB4_GROUPOFSHIPS_H
#define LAB4_GROUPOFSHIPS_H

#include <utility>
#include <list>

#include "TableOfShips.h"
#include "AircraftCarrier.h"
#include "Destroyer.h"

namespace lab4 {

    typedef std::_List_iterator<std::pair<Plane *, unsigned int>> Target_plane_it;
    typedef std::_List_iterator<std::pair<Ship *, unsigned int>> Target_ship_it;
    typedef TableOfShips::const_iterator ship_iterator;
    typedef vecPlane::const_iterator plane_iterator;

    /// Result of fight between group of ships and enemy aircraft
    enum ResultOfFight {
        win, ///< win, if group isn't destroyed and enemy aircraft destroyed
        fight_over, ///< fight over, if group and enemy aircraft cannot destroy every each
        fail ///< fail, if the group destroyed
    };

    /*!
     * @brief Target_set tells us who and how many damage got during one step of fight
     */
    struct Target_set {
        std::list<std::pair<Plane *, uint>> air;
        std::list<std::pair<Ship *, uint>> earth;
    };

    /*!
     * @brief GroupOfShip is main class - container, combines a set of ships and planes into one whole
     * @details One has fields:
     * * table, which store info about every ship
     * * commander
     * * point of departure, only name
     * * point of arrival, only name
     * * distance between point of departure and point of arrival
     */
    class GroupOfShips {
    private:
        TableOfShips table;
        Person commander;
        std::string from;
        std::string to;
        double distance{};
    public:
        /*!
         * @brief Default constructor
         */
        GroupOfShips() = default;

        /*!
         * @brief Constructor initialize all fields
         * @param _table
         * @param _commander
         * @param _from
         * @param _to
         * @param _distance
         */
        GroupOfShips(const TableOfShips& _table, Person _commander, std::string _from, std::string _to, double _distance)
        :table(_table), commander(std::move(_commander)), from(std::move(_from)), to(std::move(_to)), distance(_distance) {}

        /*!
         *
         * @return table of ships
         */
        TableOfShips getTable() const { return table; }

        /*!
         *
         * @return information about commander
         */
        Person getCommander() const { return commander; }

        /*!
         *
         * @return name of departure point
         */
        std::string getDeparturePoint() const { return from; }

        /*!
         *
         * @return name of point of arrival
         */
        std::string getPointOfArrival() const { return to; }

        /*!
         *
         * @return distance between point of departure and point of arrival
         */
        double getDistance() const { return distance; }

        /*!
         *
         * @return number of ships to group
         */
        uint getNumOfGroup() const { return table.getNumOfGroup(); }

        /*!
         *
         * @return number of planes to group
         */
        uint getNumOfPlanes() const;

        /*!
         * @brief Change old table on new table
         * @param _table
         */
        void setTable(const TableOfShips& _table) { table = _table; }

        /*!
         * @brief Change information about commander
         * @param _commander
         */
        void setCommander(Person _commander) { commander = std::move(_commander); }

        /*!
         * @brief Change name point of departure
         * @param _from
         */
        void setDeparturePoint(std::string _from) { from = std::move(_from); }

        /*!
         * @brief Change name point of arrival
         * @param _to
         */
        void setPointOfArrival(std::string _to) { to = std::move(_to); }

        /*!
         * @brief Change distance between point of departure and point of arrival
         * @param _distance
         */
        void setDistance(double _distance) { distance = _distance; }

        /*!
         *
         * @return const iterator pointer on begin container table
         */
        TableOfShips::const_iterator begin() const { return table.begin(); }

        /*!
         *
         * @return const iterator pointer on end container table
         */
        TableOfShips::const_iterator end() const { return table.end(); }

        /*!
         * @brief Find element with call sign
         * @param first
         * @return iterator point on found element or equal end()
         */
        TableOfShips::const_iterator find(const std::string& first) const { return table.find(first); }

        /*!
         * @brief Insert element to table
         * @param first call sign
         * @param second pointer on ship
         */
        void insert(const std::string& first, Ship * second) { table.insert(first, second); }

        /*!
         * @brief Erase element from table
         * @param out_it
         */
        void erase(const TableOfShips::const_iterator &out_it) { table.erase(out_it); }

        /*!
         *
         * @param typeInfo
         * @return number of ships have certain type
         */
        uint getNumShipOfType(const std::type_info &typeInfo) const;

        /*!
         * @brief Move plane from aircraft carrier to other
         * @param it_plane
         * @param it_from
         * @param it_to
         */
        static void movePlane(plane_iterator it_plane, ship_iterator it_from, ship_iterator it_to);

        /*!
         * @brief Modeling fight group with enemy aircraft
         * @details Calculate damage which group give enemy and which enemy give group,
         * after vitality every object decrease on certain quantity
         * @param enemy_aircraft
         */
        void stepOfFight(vecPlane &enemy_aircraft);

        std::ostream& print(std::ostream &output) const;

        friend std::ostream& operator <<(std::ostream &output, const GroupOfShips &group);
    };

    // Inside functions, it is here for testing with class's methods
    Target_set createTarget(vecPlane &enemy_aircraft);
    Target_set createTarget(GroupOfShips &group);
    void shipAiming(Ship *p_ship, Target_set &target, Target_plane_it &planeIt);
    void groupAiming(Target_set &target, GroupOfShips &group);
    void enemyAiming(Target_set &target, vecPlane &enemy_aircraft);
    void decreaseHealth
            (vecPlane &enemy_aircraft, GroupOfShips &group, Target_set &target_enemy, Target_set &target_group);

}



#endif //LAB4_GROUPOFSHIPS_H
