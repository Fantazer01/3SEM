//
// Created by oleg on 10.11.2021.
//

#include "Weapon.h"

Weapon::Weapon(std::string _name, std::string _ammunName, typeOfWeapon _type, int _rate, int _ammun, int _dest): name(_name), ammunitionName(_ammunName) {
    type = _type;
    rateOfFire = _rate;
    ammunition = _ammun;
    destruction = _dest;
}
