//
// Created by oleg on 10.11.2021.
//

#include "Weapon.h"
#include <stdexcept>
#include <utility>

namespace lab4 {

    Weapon::Weapon(std::string _name, std::string _ammunName, typeOfWeapon _type, int _rate, int _ammun, int _dest)
            : name(std::move(_name)), ammunitionName(std::move(_ammunName)) {
        type = _type;
        rateOfFire = _rate;
        ammunition = _ammun;
        destruction = _dest;
    }

    void Weapon::setRateOfFire(int _rate) {
        if (_rate < 0)
            throw std::invalid_argument("invalid value!");
        rateOfFire = _rate;
    }

    void Weapon::setAmmunition(int _ammunition) {
        if (_ammunition < 0)
            throw std::invalid_argument("invalid value!");
        ammunition = _ammunition;
    }

    void Weapon::setDestruction(int _destruction) {
        if (_destruction < 0)
            throw std::invalid_argument("invalid value!");
        destruction = _destruction;
    }

    void Weapon::setType(typeOfWeapon _type) {
        if (_type != light && _type != heavy)
            throw std::invalid_argument("invalid value!");
        type = _type;
    }

}