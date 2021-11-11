//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_WEAPON_H
#define LAB4_WEAPON_H

#include <string>

enum typeOfWeapon {
    light,
    heavy
};

class Weapon {
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

    //??? По всем ли полям нужны сеттеры, не будет ли это портить логику ???
    //void setName(std::string _name) { name = _name; }
    //void setAmmunitionName(std::string _name) { ammunitionName = _name; }
    void setRateOfFire(int _rate) { rateOfFire = _rate; }
    void setAmmunition(int _ammunition) { ammunition = _ammunition; }
    void setDestruction(int _destruction) { destruction = _destruction; }
    //void setType(typeOfWeapon _type) { type = _type; }

};


#endif //LAB4_WEAPON_H
