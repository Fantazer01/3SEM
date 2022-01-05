//
// Created by oleg on 10.11.2021.
//

#include <stdexcept>
#include "Plane.h"

#define hr "\n---------------------------------------------------------------------\n"

namespace lab4 {

    Plane::Plane(const vecWeapon &_armament, uint _speed, uint _vitality, uint _fuelConsumption, typePlane _type)
    : armament(_armament), speed(_speed), vitality(_vitality), fuelConsumption(_fuelConsumption), type(_type)
    {
        if (_armament.size() > 3 || (type != fighter && type != bomber))
            throw std::invalid_argument("invalid value!");
        if (type == fighter)
            for (const Weapon &weapon : _armament)
                if (weapon.getType() == Weapon::heavy)
                    throw std::invalid_argument("invalid value!");
    }

    void Plane::setArmament(const vecWeapon &_armament) {
        if (_armament.size() > 3)
            throw std::invalid_argument("invalid value!");
        if (type == fighter)
            for (const Weapon &weapon : _armament)
                if (weapon.getType() == Weapon::heavy)
                    throw std::invalid_argument("invalid value!");

        armament = _armament;
    }

    void Plane::setSpeed(uint _speed) {
        speed = _speed;
    }

    void Plane::setVitality(uint _vitality) {
        vitality = _vitality;
    }

    void Plane::setFuelConsumption(uint _fuelConsumption) {
        fuelConsumption = _fuelConsumption;
    }

    void Plane::setType(typePlane _type) {
        if (_type != fighter && _type != bomber)
            throw std::invalid_argument("invalid value!");
        if (_type == fighter)
        {
            for (auto &weapon : armament)
                if (weapon.getType() == Weapon::heavy)
                    throw std::invalid_argument("invalid value!");
        }
        type = _type;
    }

    void Plane::addWeapon(const Weapon &one) {
        if (armament.size() >= 3)
            throw std::invalid_argument("invalid value!");
        armament.push_back(one);
    }

    void Plane::changeWeapon(const Weapon &weapon, vecWeapon::const_iterator c_it) {
        if (c_it == armament.end())
            throw std::invalid_argument("invalid value!");
        if (weapon.getType() == Weapon::heavy && type == fighter)
            throw std::invalid_argument("invalid value!");

        auto it = armament.begin() + (c_it - armament.begin());
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
        output << "set of weapons: \n";
        for (const Weapon &w : plane.armament)
            output << w << hr;
        output << "speed: " << plane.speed << hr
               << "vitality: " << plane.vitality << hr
               << "fuel consumption: " << plane.fuelConsumption << hr
               << "type: " << plane.type << "\n";
        return output;
    }

}