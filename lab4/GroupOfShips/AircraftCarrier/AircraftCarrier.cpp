//
// Created by oleg on 12.11.2021.
//

#include "AircraftCarrier.h"

#include <utility>

namespace lab4 {
    AircraftCarrier::AircraftCarrier(std::string _name, Person _captain, uint _speed, uint _vitality, uint _teamMembers, std::vector<Weapon> _armament, vecPlane _planes)
    : Ship(std::move(_name), std::move(_captain), _speed, _vitality, _teamMembers), planes(std::move(_planes))
    {
        for (const Weapon &w : _armament)
            if (w.getType() == Weapon::heavy)
                throw std::invalid_argument("invalid value!");

        this->Ship::setArmament(_armament);
    }

    void AircraftCarrier::setArmament(const std::vector<Weapon> &_armament)
    {
        for (const Weapon &w : _armament)
            if (w.getType() == Weapon::heavy)
                throw std::invalid_argument("invalid value!");

        this->Ship::setArmament(_armament);
    }

    void AircraftCarrier::addWeapon(const Weapon &weapon)
    {
        if (weapon.getType() == Weapon::heavy)
            throw std::invalid_argument("invalid value!");

        this->Ship::addWeapon(weapon);
    }

    void AircraftCarrier::changeWeapon(const Weapon &weapon, std::vector<Weapon>::const_iterator c_it)
    {
        if (c_it->getType() == Weapon::heavy)
            throw std::invalid_argument("invalid value!");

        this->Ship::changeWeapon(weapon, c_it);
    }

    void AircraftCarrier::addPlane(const Plane &plane)
    {
            planes.push_back(plane);
    }

    void AircraftCarrier::changePlane(const Plane &plane, std::list<Plane>::const_iterator c_it)
    {
        if (c_it == planes.cend())
            return;
        planes.emplace(c_it, plane);
        planes.erase(c_it);
    }

    void AircraftCarrier::erasePlane(std::list<Plane>::const_iterator c_it)
    {
        if (c_it == planes.cend())
            return;
        planes.erase(c_it);
    }

    uint AircraftCarrier::calculateDamagePlanes(Target type) const
    {
        uint damage = 0;
        for (const Plane &plane : planes)
            damage += plane.calculateDamage(type);
        return damage;
    }

    std::ostream& AircraftCarrier::print(std::ostream &output) const
    {
        int i = 1;
        this->Ship::print(output);
        if (planes.empty())
            output << "Planes: empty" << std::endl;
        for (const Plane &plane : planes)
            output << "Plane" << i++ << ": " << plane << std::endl;

        return output;
    }

    std::ostream& operator <<(std::ostream &output, AircraftCarrier &ship)
    {
        ship.print(output);
        return output;
    }


}