//
// Created by oleg on 10.11.2021.
//

#include "Ship.h"
#include <stdexcept>
#include <iostream>

namespace lab4 {

    void Ship::addWeapon(const Weapon &one) {
        armament.push_back(one);
    }

    void Ship::changeWeapon(const Weapon &weapon, vecWeapon::const_iterator c_it) {
        if (c_it == armament.cend())
            throw std::invalid_argument("invalid value!");

        std::vector<Weapon>::iterator it = armament.begin() + (c_it - armament.begin());
        *it = weapon;
    }

    double Ship::maxDistance(double fuel) const {
        return 0.0;
    }

    uint Ship::calculateDamage(Target typeTarget) const {
        uint damage = 0;
        Weapon::typeOfWeapon typeWeapon = Weapon::light;

        if (typeTarget == earth)
            typeWeapon = Weapon::heavy;

        for (const Weapon &w : armament)
            if (w.getType() == typeWeapon)
                damage += w.getDestruction();
        return damage;
    }

    std::ostream& Ship::print(std::ostream &output) const {
        output << "Name of ship: " << name
               << "\ncaptain: " << captain
               << "\nspeed: " << speed
               << "\nvitality: " << vitality
               << "\nteam members: " << teamMembers
               << "\nArmament:\n";
        if (armament.empty())
            output << "There is empty\n";
        else
            for (const Weapon &a : armament)
                output << a.getName() << std::endl;
        return output;
    }

    std::ostream& operator <<(std::ostream &output, const Ship &ship)
    {
        ship.print(output);
        return output;
    }

}