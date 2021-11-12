//
// Created by oleg on 12.11.2021.
//

#ifndef LAB4_AIRCRAFTCARRIER_H
#define LAB4_AIRCRAFTCARRIER_H

#include "Ship.h"
#include "Plane.h"

namespace lab4 {

    class AircraftCarrier: public Ship {
    private:
        std::vector<Plane> planes;
    public:
        AircraftCarrier();
        AircraftCarrier(std::string name, Person captain, int speed, int vitality, int teamMembers, std::vector<Weapon> _armament)
    };

}

#endif //LAB4_AIRCRAFTCARRIER_H
