//
// Created by oleg on 10.11.2021.
//

/*!
 * @file
 * @brief Description for class Plane
 */

#ifndef LAB4_PLANE_H
#define LAB4_PLANE_H

#include "Weapon.h"
#include "Target.h"
#include <vector>

namespace lab4 {

    /*!
     * @brief class Plane describe plane
     * @details Plane can be 2 type:
     * * 1st - fighter, it can have only light weapon
     * * 2nd - bomber, it can have light or heavy weapon
     * Any plane can't have more 3 weapons
     * So Plane have fields:
     * * armament (store all weapons)
     * * speed
     * * vitality (weapon with destruction 1 can kill plane with vitality 1)
     * * fuelConsumption
     * * type
     */
    class Plane {
    public:
        /// Type of plane
        enum typePlane {
            fighter, ///< can have only light weapon
            bomber ///< can have any weapon
        };
    private:
        std::vector <Weapon> armament;
        uint speed;
        uint vitality;
        uint fuelConsumption;
        typePlane type;
    public:
        /*!
         * @brief Default constructor
         * @details armament is empty; speed, vitality, fuel are 0; type is fighter
         */
        Plane(): speed(0), vitality(0), fuelConsumption(0), type(fighter) {}

        /*!
         * @brief Constructor initialize all fields
         * @throw if armament has heavy weapon and type of plane is fighter
         * @param armament
         * @param speed
         * @param vitality
         * @param fuelConsumption
         * @param type
         */
        Plane(const std::vector<Weapon> &armament, uint speed, uint vitality, uint fuelConsumption, typePlane type);

        /*!
         *
         * @return armament of plane
         */
        std::vector<Weapon> getArmament() const { return armament; }

        /*!
         *
         * @return speed of plane
         */
        uint getSpeed() const { return speed; }

        /*!
         *
         * @return vitality of plane
         */
        uint getVitality() const { return vitality; }

        /*!
         *
         * @return fuel consumption of plane
         */
        uint getFuelConsumption() const { return fuelConsumption; }

        /*!
         *
         * @return type of plane
         */
        typePlane getType() const {return type;}

        /*!
         * Change old armament of plane on new one
         * @throw if armament has heavy weapon and type of plane is fighter
         * @throw if new armament has more 3 weapons
         * @param armament new armament of plane
         */
        void setArmament(const std::vector<Weapon> &armament);

        /*!
         * Change speed of plane
         * @param speed
         */
        void setSpeed(uint speed);

        /*!
         * Change vitality of plane
         * @param vitality
         */
        void setVitality(uint vitality);

        /*!
         * Change fuel consumption of plane
         * @param fuelConsumption
         */
        void setFuelConsumption(uint fuelConsumption);

        /*!
         * Change type of plane
         * @throw if armament has heavy weapon and type of plane is fighter
         * @param type
         */
        void setType(typePlane type);

        /*!
         * @brief Decrease vitality of plane until vitality will be 0
         * @param damage
         */
        void decreaseVitality(uint damage) { if (damage > vitality) vitality = 0; else vitality -= damage; }

        /*!
         *
         * @return number of weapon in plane's armament
         */
        uint getNumWeapon() const { return armament.size(); }

        /*!
         * @brief Add new weapon in armament
         * @throw if armament has heavy weapon and type of plane is fighter
         * @throw if new armament has more 3 weapons
         * @param weapon
         */
        void addWeapon(const Weapon &weapon);

        /*!
         * @brief Change weapon is pointed on new weapon
         * @throw if armament has heavy weapon and type of plane is fighter
         * @param weapon new weapon
         */
        void changeWeapon(const Weapon &weapon, std::vector<Weapon>::const_iterator);

        /*!
         *
         * @return iterator pointer on begin container armament
         */
        std::vector<Weapon>::const_iterator begin() const { return armament.cbegin(); }

        /*!
         *
         * @return iterator pointer on end container armament
         */
        std::vector<Weapon>::const_iterator end() const { return armament.end(); }

        /*!
         *
         * @param type type for plane is air, for ship is earth
         * @return damage which target will get if plane fight with all weapons on this target
         */
        uint calculateDamage(Target type) const;

        /*!
         * @brief Compare two plane
         * @param plane
         * @return if planes have equal all field they are equal and result is true, else false
         */
        bool operator == (const Plane &plane) const {
            if (this == &plane)
                return true;
            return
                    (speed == plane.speed &&
                    vitality == plane.vitality &&
                    fuelConsumption == plane.fuelConsumption &&
                    type == plane.type);
        }

        /*!
         * Put object of class Plane in defined stream
         * @param plane plane who will be put in stream
         * @return
         */
        friend std::ostream& operator <<(std::ostream &output, const Plane &plane);

    };

}

#endif //LAB4_PLANE_H
