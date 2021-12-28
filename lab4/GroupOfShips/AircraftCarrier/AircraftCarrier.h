//
// Created by oleg on 12.11.2021.
//

#ifndef LAB4_AIRCRAFTCARRIER_H
#define LAB4_AIRCRAFTCARRIER_H

#include "Ship.h"
#include "Plane.h"
#include <list>

namespace lab4 {

    typedef std::list<Plane> vecPlane;

    /*!
     * AircraftCarrier is heir of Ship
     * It don't have heavy weapon and stores some planes
     */
    class AircraftCarrier: public Ship {
    private:
        static const uint k = 8;
        std::list<Plane> planes;
    public:
        AircraftCarrier() = default;
        AircraftCarrier(std::string name, Person captain, uint speed, uint vitality, uint teamMembers, vecWeapon _armament=vecWeapon(), vecPlane _planes=vecPlane());

        AircraftCarrier *clone() const override { return new AircraftCarrier(*this); }

        void setArmament(const std::vector<Weapon> &_armament) override;
        void addWeapon(const Weapon &one) override;
        void changeWeapon(const Weapon &weapon, std::vector<Weapon>::const_iterator) override;

        vecPlane getPlanes() { return planes; }

        vecPlane::const_iterator beginForPlane() const { return planes.cbegin(); }
        vecPlane::const_iterator endForPlane() const { return planes.cend(); }

        vecPlane::iterator beginForPlane() { return planes.begin(); }
        vecPlane::iterator endForPlane() { return planes.end(); }

        uint getNumPlanes() const { return planes.size(); }
        void addPlane(const Plane &plane);
        void changePlane(const Plane &plane, vecPlane::const_iterator);
        void erasePlane(std::list<Plane>::const_iterator c_it);

        void setPlanes(vecPlane _planes) { planes = std::move(_planes); }

        uint calculateDamagePlanes(Target type=earth) const;

        double maxDistance(double fuel) const override { return static_cast<double>(k)*fuel; }

        virtual bool equal(const AircraftCarrier &ship) const
        { return (planes == ship.planes && (*this).Ship::equal(ship)); }

        virtual bool operator == (const AircraftCarrier &ship) const { return (*this).equal(ship); }

        std::ostream& print(std::ostream &output) const override;//вроде вывел, но это не точно
        friend  std::ostream& operator <<(std::ostream &output, AircraftCarrier &ship);
    };

}

#endif //LAB4_AIRCRAFTCARRIER_H
