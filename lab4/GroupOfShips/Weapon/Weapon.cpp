//
// Created by oleg on 10.11.2021.
//

#include "Weapon.h"
#include <stdexcept>
#include <utility>

namespace lab4 {

    Weapon::Weapon(std::string _name, std::string _ammunName, typeOfWeapon _type, uint _rate, uint _ammun, uint _dest)
            : name(std::move(_name)), ammunitionName(std::move(_ammunName)) {
        type = _type;
        rateOfFire = _rate;
        ammunition = _ammun;
        destruction = _dest;
    }

    void Weapon::setRateOfFire(uint _rate) {
        rateOfFire = _rate;
    }

    void Weapon::setAmmunition(uint _ammunition) {
        ammunition = _ammunition;
    }

    void Weapon::setDestruction(uint _destruction) {
        destruction = _destruction;
    }

    void Weapon::setType(typeOfWeapon _type) {
        if (_type != light && _type != heavy)
            throw std::invalid_argument("invalid value!");
        type = _type;
    }

    std::ostream& operator << (std::ostream &output, Weapon &weapon) {
        output << "Name: " << weapon.name
               << "\nName of ammunition: " << weapon.ammunitionName
               << "\nRate of fire: " << weapon.rateOfFire
               << "\nAmmunition: " << weapon.ammunition
               << "\nDestruction: " << weapon.destruction
               << "\nType: ";
        if (weapon.type == Weapon::light)
            output << "light\n";
        else
            output << "hard\n";
        return output;
    }

}