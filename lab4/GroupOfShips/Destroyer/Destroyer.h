//
// Created by oleg on 12.11.2021.
//

#ifndef LAB4_DESTROYER_H
#define LAB4_DESTROYER_H

#include <utility>

#include "Ship.h"

namespace lab4 {

    class Destroyer : public Ship {
    private:
        static const uint k = 11;
        Ship *covered;
    public:
        Destroyer() = default;
        Destroyer(std::string _name, Person _captain, uint _speed, uint _vitality, uint _teamMembers, vecWeapon _armament, Ship* _covered = nullptr)
        : Ship(std::move(_name), std::move(_captain), _speed, _vitality, _teamMembers, std::move(_armament)), covered(_covered) {}

        virtual Destroyer *clone() const { return new Destroyer(*this); }

        Ship * getCovered() const { return covered; }
        void setCovered(Ship *_covered) { covered = _covered; }

        virtual bool equal(const Destroyer &ship) const
        { return (covered == ship.covered && (*this).Ship::equal(ship)); }

        virtual bool operator == (const Destroyer &ship) const { return (*this).equal(ship); }

        double maxDistance(double fuel) const override { return static_cast<double>(k)*fuel; }

        std::ostream& print(std::ostream &output) const override;//вроде вывел, но это не точно
        friend  std::ostream& operator <<(std::ostream &output, Destroyer &ship);
    };

}

#endif //LAB4_DESTROYER_H
