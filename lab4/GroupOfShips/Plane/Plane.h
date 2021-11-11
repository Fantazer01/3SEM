//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_PLANE_H
#define LAB4_PLANE_H

#include "Weapon.h"
#include <vector>

namespace lab4 {

    enum typePlane {
        fighter,
        bomber
    };

    class Plane {
    private:
        std::vector <Weapon> armament;
        int speed;
        int vitality;
        int fuelConsumption;
        typePlane type;
    public:
        Plane(): speed(0), vitality(0), fuelConsumption(0), type(fighter) {}
        Plane(std::vector<Weapon> _armament, int _speed, int _vitality, int _fuelConsumption, typePlane _type);

        std::vector<Weapon> getArmament() const { return armament; }
        int getSpeed() const { return speed; }
        int getVitality() const { return vitality; }
        int getFuelConsumption() const { return fuelConsumption; }
        typePlane getType() const {return type;}

        void setArmament(std::vector<Weapon> _armament);
        void setSpeed(int _speed);
        void setVitality(int _vitality);
        void setFuelConsumption(int _fuelConsumption);
        void setType(typePlane _type);

        /* ??? нужно ли добавлять оружие, нужно ли его удалять, если да, то как ???
        void addWeapon();
        void removeWeapon();
        */
    };

}

#endif //LAB4_PLANE_H
