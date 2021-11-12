//
// Created by oleg on 10.11.2021.
//

#include "Ship.h"
#include <stdexcept>

namespace lab4 {

    Ship::Ship(std::string _name, Person _captain, int _speed, int _vitality, int _teamMembers, std::vector<Weapon> _armament)
    : name(_name), captain(_captain), speed(_speed), vitality(_vitality), teamMembers(_teamMembers), armament(_armament) {
        if (_speed < 0 || _vitality < 0 || _teamMembers < 0)
            throw std::invalid_argument("invalid value!");
    }

    void Ship::setName(std::string _name) {
        name = _name;
    }

    void Ship::setInfoCaptain(Person _captain) {
        captain = _captain;
    }

    void Ship::setSpeed(int _speed) {
        if (_speed < 0)
            throw std::invalid_argument("invalid value!");
        speed = _speed;
    }

    void Ship::setVitality(int _vitality) {
        if (_vitality < 0)
            throw std::invalid_argument("invalid value!");
        vitality = _vitality;
    }

    void Ship::setTeamMembers(int _teamMembers) {
        if (_teamMembers < 0)
            throw std::invalid_argument("invalid value!");
        teamMembers = _teamMembers;
    }

}