//
// Created by oleg on 10.11.2021.
//

#include <stdexcept>
#include "Plane.h"

namespace lab4 {

    Plane::Plane(std::vector<Weapon> _armament, int _speed, int _vitality, int _fuelConsumption, typePlane _type): armament(_armament), speed(_speed), vitality(_vitality), fuelConsumption(_fuelConsumption), type(_type) {
        if (_armament.size() > 3 || _speed < 0 || _vitality < 0 || _fuelConsumption || (type != fighter && type != bomber))
            throw std::invalid_argument("invalid value!");
        if (type == fighter)
            for (Weapon &weapon : _armament)
                if (weapon.getType() == heavy)
                    throw std::invalid_argument("invalid value!");
    }

    void Plane::setArmament(std::vector<Weapon> _armament) {
        if (_armament.size() > 3)
            throw std::invalid_argument("invalid value!");
        if (type == fighter)
            for (Weapon &weapon : _armament)
                if (weapon.getType() == heavy)
                    throw std::invalid_argument("invalid value!");

        armament = _armament;
    }

    void Plane::setSpeed(int _speed) {
        if (_speed < 0)
            throw std::invalid_argument("invalid value!");
        speed = _speed;
    }

    void Plane::setVitality(int _vitality) {
        if (_vitality < 0)
            throw std::invalid_argument("invalid value!");
        vitality = _vitality;
    }

    void Plane::setFuelConsumption(int _fuelConsumption) {
        if (_fuelConsumption < 0)
            throw std::invalid_argument("invalid value!");
        fuelConsumption = _fuelConsumption;
    }

    void Plane::setType(typePlane _type) {
        if (_type != fighter && _type != bomber)
            throw std::invalid_argument("invalid value!");
        type = _type;
    }

    void Plane::addWeapon(const Weapon &one) {
        if (armament.size() >= 3)
            throw std::invalid_argument("invalid value!");
        armament.push_back(one);
    }

}