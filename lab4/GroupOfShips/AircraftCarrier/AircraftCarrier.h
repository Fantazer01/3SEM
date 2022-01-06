//
// Created by oleg on 12.11.2021.
//

/*!
 * @file
 * @brief Description for class AircraftCarrier (inheritance of class Ship)
 */

#ifndef LAB4_AIRCRAFTCARRIER_H
#define LAB4_AIRCRAFTCARRIER_H

#include "Ship.h"
#include "Plane.h"
#include <list>

namespace lab4 {

    typedef std::list<Plane> vecPlane;

    /*!
     *
     */
    /*!
     * @brief class AircraftCarrier is inheritance of class Ship;
     * @details Difference between AircraftCarrier and Ship:
     * * object have type AircraftCarrier can't have heavy weapon
     * * object have type AircraftCarrier have field planes, where store info about plane on board
     */
    class AircraftCarrier: public Ship {
    private:
        static const uint k = 8;
        std::list<Plane> planes;
    public:
        /*!
         * @brief Default constructor as ship's default constructor, also field planes is empty
         */
        AircraftCarrier() = default;

        /*!
         * @brief Constructor initialize all fields
         * @param name
         * @param captain
         * @param speed
         * @param vitality
         * @param teamMembers
         * @param _armament
         * @param _planes
         */
        AircraftCarrier(std::string name, Person captain, uint speed, uint vitality, uint teamMembers, vecWeapon armament=vecWeapon(), vecPlane planes=vecPlane());

        /*!
         * @brief Virtual destructor do nothing
         */
        ~AircraftCarrier() override = default;

        /*!
         * @brief New object is dynamic created, using for inheritance class
         * @return pointer on copy this object
         */
        AircraftCarrier *clone() const override { return new AircraftCarrier(*this); }

        /*!
         * @brief Change armament - all container of ship
         * @throw if armament have type no light
         * @param _armament
         */
        void setArmament(const vecWeapon &armament) override;

        /*!
         * @brief Add new weapon in armament
         * @throw if armament have type no light
         * @param weapon
         */
        void addWeapon(const Weapon &one) override;

        /*!
         * @brief Change weapon is pointed on new weapon
         * @param weapon new weapon
         */
        void changeWeapon(const Weapon &weapon, std::vector<Weapon>::const_iterator) override;

        /*!
         *
         * @return planes - all container
         */
        vecPlane getPlanes() { return planes; }

        /*!
         *
         * @return const iterator pointer on begin container planes
         */
        vecPlane::const_iterator beginForPlane() const { return planes.cbegin(); }

        /*!
         *
         * @return const iterator pointer on end container planes
         */
        vecPlane::const_iterator endForPlane() const { return planes.cend(); }

        /*!
         *
         * @return iterator pointer on begin container planes
         */
        vecPlane::iterator beginForPlane() { return planes.begin(); }

        /*!
         *
         * @return iterator pointer on end container planes
         */
        vecPlane::iterator endForPlane() { return planes.end(); }

        /*!
         *
         * @return number of plane on ship
         */
        uint getNumPlanes() const { return planes.size(); }

        /*!
         * @brief Add new plane to the container
         * @param plane
         */
        void addPlane(const Plane &plane);

        /*!
         * Change old plane pointed by iterator on new plane
         * @param plane
         */
        void changePlane(const Plane &plane, vecPlane::const_iterator);

        /*!
         * Erase plane pointed iterator
         * @param c_it
         */
        void erasePlane(vecPlane::const_iterator c_it);

        /*!
         * Change all container of planes
         * @param _planes
         */
        void setPlanes(vecPlane _planes) { planes = std::move(_planes); }

        /*!
         * @brief Calculating damage for target if use every possible plane's weapon every plane
         * @param type if ship - earth; if plane - air
         * @return
         */
        uint calculateDamagePlanes(Target type=earth) const;

        /*!
         * It is product fuel and coefficient ( same it for every ships have same type)
         * @param fuel
         * @return
         */
        double maxDistance(double fuel) const override { return static_cast<double>(k)*fuel; }

        /*!
         * Compare two ship
         * @param ship
         * @return if ships have equal all field they are equal and result is true, else false
         */
        virtual bool equal(const AircraftCarrier *ship) const
        {
            if (typeid(*this) != typeid(*ship)) return false;
            return (planes == ship->planes && (*this).Ship::equal(ship));
        }

        /*!
         * @brief Compare two ship
         * @param ship
         * @return if ships have equal all field they are equal and result is true, else false
         */
        virtual bool operator == (const AircraftCarrier &ship) const { return (*this).equal(&ship); }

        /*!
         * @brief Put object of class Ship in defined stream
         * @param output
         * @return
         */
        std::ostream& print(std::ostream &output) const override;

        /*!
         * @brief Doing same method print, because use it
         * @param output
         * @param ship
         * @return
         */
        friend  std::ostream& operator <<(std::ostream &output, AircraftCarrier &ship);
    };

}

#endif //LAB4_AIRCRAFTCARRIER_H
