//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_PLANE_H
#define LAB4_PLANE_H

#include "Weapon.h"
#include "Target.h"
#include <vector>

namespace lab4 {

    class Plane {
    public:
        enum typePlane {
            fighter,
            bomber
        };
    private:
        std::vector <Weapon> armament;
        uint speed;
        uint vitality;
        uint fuelConsumption;
        typePlane type;
    public:
        Plane(): speed(0), vitality(0), fuelConsumption(0), type(fighter) {}
        Plane(const std::vector<Weapon> &_armament, uint _speed, uint _vitality, uint _fuelConsumption, typePlane _type);

        std::vector<Weapon> getArmament() const { return armament; }
        uint getSpeed() const { return speed; }
        uint getVitality() const { return vitality; }
        uint getFuelConsumption() const { return fuelConsumption; }
        typePlane getType() const {return type;}

        void setArmament(const std::vector<Weapon> &_armament);
        void setSpeed(unsigned int _speed);
        void setVitality(unsigned int _vitality);
        void setFuelConsumption(unsigned int _fuelConsumption);
        void setType(typePlane _type);

        uint getNumWeapon() const { return armament.size(); }
        void addWeapon(const Weapon &weapon);
        void changeWeapon(const Weapon &weapon, std::vector<Weapon>::const_iterator);

        std::vector<Weapon>::const_iterator begin() const { return armament.cbegin(); }
        std::vector<Weapon>::const_iterator end() const { return armament.end(); }

        uint calculateDamage(Target type) const;

        bool operator == (const Plane &plane) const {
            return
                    (speed == plane.speed &&
                    vitality == plane.vitality &&
                    fuelConsumption == plane.fuelConsumption &&
                    type == plane.type);
        }

        friend std::ostream& operator <<(std::ostream &output, const Plane &plane);

    };

}

#endif //LAB4_PLANE_H
