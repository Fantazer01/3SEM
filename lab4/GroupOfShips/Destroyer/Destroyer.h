//
// Created by oleg on 12.11.2021.
//

/*!
 * @file
 * @brief Description for class Destroyer (inheritance of class Ship)
 */

#ifndef LAB4_DESTROYER_H
#define LAB4_DESTROYER_H

#include <utility>
#include "Ship.h"

namespace lab4 {

    /*!
     * @brief class Destroyer is inheritance of class Ship; Difference is field covered - pointer on ship
     */
    class Destroyer : public Ship {
    private:
        static const uint k = 11;
        Ship *covered = nullptr;
    public:
        /*!
         * @brief Default constructor as ship's default constructor, also field covered is nullptr
         */
        Destroyer() = default;
        /*!
         * @brief Constructor initialize all fields
         * @param _name
         * @param _captain
         * @param _speed
         * @param _vitality
         * @param _teamMembers
         * @param _armament
         * @param _covered
         */
        Destroyer(std::string _name, Person _captain, uint _speed, uint _vitality, uint _teamMembers, vecWeapon _armament, Ship* _covered = nullptr)
        : Ship(std::move(_name), std::move(_captain), _speed, _vitality, _teamMembers, std::move(_armament)), covered(_covered) {}

        /*!
         * @brief Virtual destructor do nothing
         */
        ~Destroyer() override = default;

        /*!
         * @brief New object is dynamic created, using for inheritance class
         * @return pointer on copy this object
         */
        Destroyer *clone() const override { return new Destroyer(*this); }

        /*!
         *
         * @return pointer on covered ship
         */
        Ship * getCovered() const { return covered; }

        /*!
         * Change pointer on covered ship
         * @param _covered
         */
        void setCovered(Ship *_covered) { covered = _covered; }

        /*!
         * @brief Compare two ship
         * @param ship pointer on ship
         * @return if ships have equal all field they are equal and result is true, else false
         */
        virtual bool equal(const Destroyer *ship) const
        {
            if (this == ship) return true;
            if (typeid(*this) != typeid(*ship)) return false;
            return (covered == ship->covered && (*this).Ship::equal(ship));
        }

        /*!
         * @brief Compare two ship
         * @param ship
         * @return if ships have equal all field they are equal and result is true, else false
         */
        virtual bool operator == (const Destroyer &ship) const { return (*this).equal(&ship); }

        /*!
         * @brief It is product fuel and coefficient ( same it for every ships have same type)
         * @param fuel
         * @return distance which ship can go
         */
        double maxDistance(double fuel) const override { return static_cast<double>(k)*fuel; }

        /*!
         * @brief Put object of class Ship in defined stream
         * @param output
         * @return
         */
        std::ostream& print(std::ostream &output) const override;

        /*!
         * @brief Doing same method print, because use it
         * @param output
         * @param ship
         * @return
         */
        friend std::ostream& operator <<(std::ostream &output, Destroyer &ship);
    };

}

#endif //LAB4_DESTROYER_H
