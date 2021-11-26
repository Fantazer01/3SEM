//
// Created by oleg on 12.11.2021.
//

#ifndef LAB4_AIRCRAFTCARRIER_H
#define LAB4_AIRCRAFTCARRIER_H

#include "Ship.h"
#include "Plane.h"
#include "Target.h"

namespace lab4 {

    class AircraftCarrier: public Ship {
    private:
        typedef std::vector<Weapon> vecWeapon;
        typedef std::vector<Plane> vecPlane;
    private:
        std::vector<Plane> planes;
    public:
        AircraftCarrier() = default;
        AircraftCarrier(std::string name, Person captain, uint speed, uint vitality, uint teamMembers, vecWeapon _armament=vecWeapon(), vecPlane _planes=vecPlane());

        void setArmament(const std::vector<Weapon> &_armament) override;
        void addWeapon(const Weapon &one) override;
        void changeWeapon(const Weapon &weapon, std::vector<Weapon>::const_iterator) override;

        std::vector<Plane> getPlanes() { return planes; }

        std::vector<Plane>::const_iterator beginForPlane() const { return planes.cbegin(); }
        std::vector<Plane>::const_iterator endForPlane() const { return planes.cend(); }

        uint getNumPlanes() const { return planes.size(); }
        void addPlane(const Plane &plane);
        void changePlane(const Plane &plane, std::vector<Plane>::const_iterator);

        void setPlanes(std::vector<Plane> _planes) { planes = std::move(_planes); }

        uint calculateDamagePlanes(Target type=earth) const;

        std::ostream& print(std::ostream &output) const override;//вроде вывел, но это не точно
        friend  std::ostream& operator <<(std::ostream &output, AircraftCarrier &ship);
    };

}

#endif //LAB4_AIRCRAFTCARRIER_H
