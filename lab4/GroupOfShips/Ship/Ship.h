//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_SHIP_H
#define LAB4_SHIP_H

#include <utility>
#include <vector>
#include "Person.h"
#include "Weapon.h"
#include "Target.h"

namespace lab4 {

    typedef std::vector<Weapon> vecWeapon;
    /*!
     * @brief Ship is parent class
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
        Ship(): speed(0), vitality(0), teamMembers(0) {}
        Ship(std::string _name, Person _captain, uint _speed, uint _vitality, uint _teamMembers, vecWeapon _armament=vecWeapon())
                : name(std::move(_name)), captain(std::move(_captain)), speed(_speed), vitality(_vitality), teamMembers(_teamMembers), armament(std::move(_armament)) {}
        virtual ~Ship() = default;

        virtual Ship *clone() const { return new Ship(*this); }

        std::string getName() const { return name; }
        Person getInfoCaptain() const { return captain; }
        uint getSpeed() const { return speed; }
        uint getVitality() const { return vitality; }
        uint getTeamMembers() const { return teamMembers; }
        vecWeapon getArmament() const { return armament; }

        void setName(std::string _name) { name = std::move(_name); }
        void setInfoCaptain(Person _captain) { captain = std::move(_captain); }
        void setSpeed(uint _speed) { speed = _speed; }
        void setVitality(uint _vitality) { vitality = _vitality; }
        void setTeamMembers(uint _teamMembers) { teamMembers = _teamMembers; }
        virtual void setArmament(const std::vector<Weapon> &_armament) { armament = _armament; }

        void decreaseVitality(uint damage) { if (damage > vitality) vitality = 0; else vitality -= damage; }

        vecWeapon::const_iterator beginForWeapon() const { return armament.cbegin(); }
        vecWeapon::const_iterator endForWeapon() const { return armament.cend(); }

        uint getNumWeapon() const { return armament.size(); }
        virtual void addWeapon(const Weapon &weapon);
        virtual void changeWeapon(const Weapon &weapon, vecWeapon::const_iterator);

        virtual double maxDistance(double fuel) const;
        uint calculateDamage(Target type=earth) const;
        virtual std::ostream& print(std::ostream &output) const;
        friend  std::ostream& operator <<(std::ostream &output, const Ship &ship);

        virtual bool equal(const Ship &ship) const
        { return (name == ship.name &&
                  captain == ship.captain &&
                  speed == ship.speed &&
                  vitality == ship.vitality &&
                  teamMembers == ship.teamMembers &&
                  armament == ship.armament); }

        virtual bool operator == (const Ship &ship) const { return (*this).equal(ship); }

    };

}

#endif //LAB4_SHIP_H
