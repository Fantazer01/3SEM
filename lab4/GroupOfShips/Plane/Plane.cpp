//
// Created by oleg on 10.11.2021.
//

#include <stdexcept>
#include "Plane.h"

namespace lab4 {

    Plane::Plane(const std::vector<Weapon> &_armament, uint _speed, uint _vitality, uint _fuelConsumption, typePlane _type)
    : armament(_armament), speed(_speed), vitality(_vitality), fuelConsumption(_fuelConsumption), type(_type) {
        if (_armament.size() > 3 || (type != fighter && type != bomber))
            throw std::invalid_argument("invalid value!");
        if (type == fighter)
            for (const Weapon &weapon : _armament)
                if (weapon.getType() == Weapon::heavy)
                    throw std::invalid_argument("invalid value!");
    }

    void Plane::setArmament(const std::vector<Weapon> &_armament) {
        if (_armament.size() > 3)
            throw std::invalid_argument("invalid value!");
        if (type == fighter)
            for (const Weapon &weapon : _armament)
                if (weapon.getType() == Weapon::heavy)
                    throw std::invalid_argument("invalid value!");

        armament = _armament;
    }

    void Plane::setSpeed(uint _speed) {
        if (_speed < 0)
            throw std::invalid_argument("invalid value!");
        speed = _speed;
    }

    void Plane::setVitality(uint _vitality) {
        if (_vitality < 0)
            throw std::invalid_argument("invalid value!");
        vitality = _vitality;
    }

    void Plane::setFuelConsumption(uint _fuelConsumption) {
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

    void Plane::changeWeapon(const Weapon &weapon, std::vector<Weapon>::const_iterator c_it) {
        if (c_it == armament.end())
            throw std::invalid_argument("invalid value!");
        if (weapon.getType() == Weapon::heavy && type == fighter)
            throw std::invalid_argument("invalid value!");

        std::vector<Weapon>::iterator it = armament.begin() + (c_it - armament.begin());
        *it = weapon;
    }

    uint Plane::calculateDamage(Target typeTarget) const
    {
        uint damage = 0;
        Weapon::typeOfWeapon typeWeapon = Weapon::light;

        if (typeTarget == earth)
            typeWeapon = Weapon::heavy;

        for (const Weapon &w : armament)
            if (w.getType() == typeWeapon)
                damage += w.getDestruction();
        return damage;
    }

    std::ostream& operator <<(std::ostream &output, const Plane &plane)
    {
        output << "set of weapons: ";
        for (const Weapon &w : plane.armament)
            output << w << " ";
        output << std::endl
               << "speed: " << plane.speed
               << "vitality: " << plane.vitality
               << "fuel consumption: " << plane.fuelConsumption
               << "type: " << plane.type;
    }

}