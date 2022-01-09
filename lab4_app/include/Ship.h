//
// Created by oleg on 10.11.2021.
//

/*!
 * @file
 * @brief Description for class Ship
 */

#ifndef LAB4_SHIP_H
#define LAB4_SHIP_H

#include <utility>
#include <vector>
#include "Person.h"
#include "Weapon.h"
#include "Target.h"

namespace lab4 {

    /*!
     * @brief class Ship describe ship; Ship is parent class
     * @details Ship have fields:
     * * name of ship
     * * information about captain of ship in class Person
     * * speed
     * * vitality
     * * number of team member
     * * armament of ship
     */
    class Ship {
    private:
        static const uint k = 10;/// < constant is used for calculating distance
        std::string name;
        Person captain;
        uint speed;
        uint vitality;
        uint teamMembers;
        vecWeapon armament;
    public:
        /*!
         * @brief Default constructor
         * @details fields name, captain and armament are empty, speed, vitality, number of team members are 0
         */
        Ship(): speed(0), vitality(0), teamMembers(0) {}

        /*!
         * Constructor initialize all fields
         * @param _name
         * @param _captain
         * @param _speed
         * @param _vitality
         * @param _teamMembers
         * @param _armament
         */
        Ship(std::string _name, Person _captain, uint _speed, uint _vitality, uint _teamMembers, vecWeapon _armament=vecWeapon())
                : name(std::move(_name)), captain(std::move(_captain)), speed(_speed), vitality(_vitality), teamMembers(_teamMembers), armament(std::move(_armament)) {}

        /*!
         * @brief Virtual destructor do nothing
         */
        virtual ~Ship() = default;

        /*!
         * @brief New object is dynamic created, using for inheritance class
         * @return pointer on copy this object
         */
        virtual Ship* clone() const { return new Ship(*this); }

        /*!
         *
         * @return name of ship
         */
        std::string getName() const { return name; }

        /*!
         *
         * @return information about captain
         */
        Person getInfoCaptain() const { return captain; }

        /*!
         *
         * @return speed of ship
         */
        uint getSpeed() const { return speed; }

        /*!
         *
         * @return vitality of ship
         */
        uint getVitality() const { return vitality; }

        /*!
         *
         * @return number of team member of ship
         */
        uint getTeamMembers() const { return teamMembers; }

        /*!
         *
         * @return armament - all container
         */
        vecWeapon getArmament() const { return armament; }

        /*!
         * Change name of ship
         * @param _name
         */
        void setName(std::string _name) { name = std::move(_name); }

        /*!
         * Change information about captain
         * @param _captain
         */
        void setInfoCaptain(Person _captain) { captain = std::move(_captain); }

        /*!
         * Change speed of ship
         * @param _speed
         */
        void setSpeed(uint _speed) { speed = _speed; }

        /*!
         * Change vitality of ship
         * @param _vitality
         */
        void setVitality(uint _vitality) { vitality = _vitality; }

        /*!
         * Change team member of ship
         * @param _teamMembers
         */
        void setTeamMembers(uint _teamMembers) { teamMembers = _teamMembers; }

        /*!
         * Change armament - all container of ship
         * @param _armament
         */
        virtual void setArmament(const std::vector<Weapon> &_armament) { armament = _armament; }

        /*!
         * @brief Decrease vitality of ship until vitality will be 0
         * @param damage
         */
        void decreaseVitality(uint damage) { if (damage > vitality) vitality = 0; else vitality -= damage; }

        /*!
         *
         * @return iterator pointer on begin container armament
         */
        vecWeapon::const_iterator beginForWeapon() const { return armament.cbegin(); }

        /*!
         *
         * @return iterator pointer on end container armament
         */
        vecWeapon::const_iterator endForWeapon() const { return armament.cend(); }

        /*!
         *
         * @return number of weapon in ship's armament
         */
        uint getNumWeapon() const { return armament.size(); }

        /*!
         * @brief Add new weapon in armament
         * @param weapon
         */
        virtual void addWeapon(const Weapon &weapon);

        /*!
         * @brief Change weapon is pointed on new weapon
         * @param weapon new weapon
         */
        virtual void changeWeapon(const Weapon &weapon, vecWeapon::const_iterator);

        /*!
         * @brief It is product fuel and coefficient ( same it for every ships have same type)
         * @param fuel
         * @return distance which ship can go
         */
        virtual double maxDistance(double fuel) const;

        /*!
         * @brief Calculating damage for target if use every possible weapon
         * @param type if ship - earth; if plane - air
         * @return
         */
        uint calculateDamage(Target type=earth) const;

        /*!
         * @brief Put object of class Ship in defined stream
         * @param output
         * @return
         */
        virtual std::ostream& print(std::ostream &output) const;

        virtual std::ostream& print(std::ostream &output, const std::string &beginChar) const;

        /*!
         * @brief Doing same method print, because use it
         * @param output
         * @param ship
         * @return
         */
        friend std::ostream& operator <<(std::ostream &output, const Ship &ship);

        /*!
         * @brief Compare two ship
         * @param ship pointer on ship
         * @return if ships have equal all field they are equal and result is true, else false
         */
        virtual bool equal(const Ship *ship) const
        {
            if (this == ship)
                return true;
            return
                 (name == ship->name &&
                  captain == ship->captain &&
                  speed == ship->speed &&
                  vitality == ship->vitality &&
                  teamMembers == ship->teamMembers &&
                  armament == ship->armament);
        }

        /*!
         * @brief Compare two ship
         * @param ship
         * @return if ships have equal all field they are equal and result is true, else false
         */
        virtual bool operator == (const Ship &ship) const { return (*this).equal(&ship); }

    };

}

#endif //LAB4_SHIP_H
