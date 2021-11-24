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
        int rateOfFire;
        int ammunition;
        int destruction;
        typeOfWeapon type;
    public:
        Weapon(): rateOfFire(0), ammunition(0), destruction(0), type(light) {}

        Weapon(std::string _name, std::string _ammunName, typeOfWeapon _type=light, int _rate=0, int _ammun=0, int _destruction=0);

        std::string getName() const { return name; }
        std::string getAmmunitionName() const { return ammunitionName; }
        int getRateOfFire() const { return rateOfFire; }
        int getAmmunition() const { return ammunition; }
        int getDestruction() const { return destruction; }
        typeOfWeapon getType() const { return type; }

        void setName(std::string _name) { name = std::move(_name); }
        void setAmmunitionName(std::string _name) { ammunitionName = std::move(_name); }
        void setRateOfFire(int _rate);
        void setAmmunition(int _ammunition);
        void setDestruction(int _destruction);
        void setType(typeOfWeapon _type);

        friend std::ostream& operator << (std::ostream &, Weapon &);

    };

}


#endif //LAB4_WEAPON_H
