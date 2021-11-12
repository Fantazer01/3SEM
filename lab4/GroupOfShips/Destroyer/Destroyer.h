//
// Created by oleg on 12.11.2021.
//

#ifndef LAB4_DESTROYER_H
#define LAB4_DESTROYER_H

#include "Ship.h"

namespace lab4 {

    class Destroyer : public Ship {
    private:
        Ship *covered;
    public:
        Destroyer();
        Destroyer(std::string name, Person captain, int speed, int vitality, int teamMembers, std::vector<Weapon> _armament, Ship* _covered = nullptr);

    };

}

#endif //LAB4_DESTROYER_H
