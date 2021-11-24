//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_WEAPON_H
#define LAB4_WEAPON_H

#include <string>
#include <iostream>
#include <utility>

namespace lab4 {

    class Weapon {
    public:
        enum typeOfWeapon {
            light,
            heavy
        };
    private:
        std::string name;
        std::string ammunitionName;
        uint rateOfFire;
        uint ammunition;
        uint destruction;
        typeOfWeapon type;
    public:
        Weapon(): rateOfFire(0), ammunition(0), destruction(0), type(light) {}

        Weapon(std::string _name, std::string _ammunName, typeOfWeapon _type=light, uint _rate=0, uint _ammun=0, uint _destruction=0);

        std::string getName() const { return name; }
        std::string getAmmunitionName() const { return ammunitionName; }
        uint getRateOfFire() const { return rateOfFire; }
        uint getAmmunition() const { return ammunition; }
        uint getDestruction() const { return destruction; }
        typeOfWeapon getType() const { return type; }

        void setName(std::string _name) { name = std::move(_name); }
        void setAmmunitionName(std::string _name) { ammunitionName = std::move(_name); }
        void setRateOfFire(uint _rate);
        void setAmmunition(uint _ammunition);
        void setDestruction(uint _destruction);
        void setType(typeOfWeapon _type);

        friend std::ostream& operator << (std::ostream &, Weapon &);

    };

}


#endif //LAB4_WEAPON_H
