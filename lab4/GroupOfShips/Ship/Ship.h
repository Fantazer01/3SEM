//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_SHIP_H
#define LAB4_SHIP_H

#include <vector>
#include "Person.h"
#include "Weapon.h"

namespace lab4 {

    class Ship {
    private:
        std::string name;
        Person captain;
        int speed;
        int vitality;
        int teamMembers;
        std::vector <Weapon> armament;
    public:
        Ship(): speed(0), vitality(0), teamMembers(0) {}
        Ship(std::string name, Person captain, int speed, int vitality, int teamMembers, std::vector<Weapon> _armament);

        std::string getName() const { return name; }
        Person getInfoCaptain() const { return captain; }
        int getSpeed() const { return speed; }
        int getVitality() const { return vitality; }
        int getTeamMembers() const { return teamMembers; }

        void setName(std::string _name);
        void setInfoCaptain(Person _captain);
        void setSpeed(int );
        void setVitality(int );
        void setTeamMembers(int );

    };

}

#endif //LAB4_SHIP_H
