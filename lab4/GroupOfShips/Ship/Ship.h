//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_SHIP_H
#define LAB4_SHIP_H

#include <utility>
#include <vector>
#include "Person.h"
#include "Weapon.h"

namespace lab4 {

    class Ship {
    private:
        std::string name;
        Person captain;
        uint speed;
        uint vitality;
        uint teamMembers;
        std::vector <Weapon> armament;
    public:
        Ship(): speed(0), vitality(0), teamMembers(0) {}
        Ship(std::string _name, Person _captain, uint _speed, uint _vitality, uint _teamMembers, std::vector<Weapon> _armament=std::vector<Weapon>())
                : name(std::move(_name)), captain(std::move(_captain)), speed(_speed), vitality(_vitality), teamMembers(_teamMembers), armament(std::move(_armament)) {}

        std::string getName() const { return name; }
        Person getInfoCaptain() const { return captain; }
        uint getSpeed() const { return speed; }
        uint getVitality() const { return vitality; }
        uint getTeamMembers() const { return teamMembers; }
        std::vector<Weapon> getArmament() const { return armament; }

        void setName(std::string _name) { name = std::move(_name); }
        void setInfoCaptain(Person _captain) { captain = std::move(_captain); }
        void setSpeed(uint _speed) { speed = _speed; }
        void setVitality(uint _vitality) { vitality = _vitality; }
        void setTeamMembers(uint _teamMembers) { teamMembers = _teamMembers; }
        void setArmament(const std::vector<Weapon> &_armament) { armament = _armament; }

        std::vector<Weapon>::const_iterator begin() const { return armament.cbegin(); }
        std::vector<Weapon>::const_iterator end() const { return armament.cend(); }

        uint getNumWeapon() const { return armament.size(); }
        void addWeapon(const Weapon &weapon);
        void changeWeapon(const Weapon &weapon, std::vector<Weapon>::const_iterator);

        double maxDistance(double fuel) const;//какая тут формула???
        std::ostream& print(std::ostream &output) const;//вроде вывел, но это не точно

    };

}

#endif //LAB4_SHIP_H
