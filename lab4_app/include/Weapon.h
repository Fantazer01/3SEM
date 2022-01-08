//
// Created by oleg on 10.11.2021.
//

/*!
 * @file
 * @brief There is description class of Weapon
 */

#ifndef LAB4_WEAPON_H
#define LAB4_WEAPON_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>

namespace lab4 {

    /*!
     * @brief class Weapon describe weapon used by plane, ship and other object
     * @details
     * Weapon can be 2 types:
     * 1st - light, for destroying planes;
     * 2nd - heavy, for destroying ships.
     * Also it has:
     * * name of weapon
     * * name of ammunition
     * * rate of fire
     * * destruction for target
     * * type of weapon
     */
    class Weapon {
    public:
        /// Type of weapon
        enum typeOfWeapon {
            light, ///< Weapon for fight with planes
            heavy  ///< Weapon for fight with ship
        };
    private:
        std::string name;
        std::string ammunitionName;
        uint rateOfFire;
        uint ammunition;
        uint destruction;
        typeOfWeapon type;
    public:
        /*!
         * @brief Default constructor
         * @details Names of weapon and ammunition is empty string;
         * rate, ammunition and destruction are 0;
         * type is light.
         */
        Weapon(): rateOfFire(0), ammunition(0), destruction(0), type(light) {}

        /*!
         * @brief Constructor initialize all fields of class Person
         * @details You can fill only names of weapon and ammunition, other fields will state how in default constructor
         * @param _name name of weapon
         * @param _ammunName name of ammunition
         * @param _type type of weapon
         * @param _rate rate of fire
         * @param _ammun number of ammunition
         * @param _destruction destruction for target
         */
        Weapon(std::string _name, std::string _ammunName, typeOfWeapon _type=light, uint _rate=0, uint _ammun=0, uint _destruction=0);

        /*!
         * @brief Return name of weapon
         * @return
         */
        std::string getName() const { return name; }

        /*!
         * @brief Return ammunition name
         * @return
         */
        std::string getAmmunitionName() const { return ammunitionName; }

        /*!
         * @brief Return number rate of fire
         * @return
         */
        uint getRateOfFire() const { return rateOfFire; }

        /*!
         * @brief Return number of ammunition
         * @return
         */
        uint getAmmunition() const { return ammunition; }

        /*!
         * @brief Return number of destruction
         * @return
         */
        uint getDestruction() const { return destruction; }
        /*!
         * @brief Return type of weapon
         * @return
         */
        typeOfWeapon getType() const { return type; }

        /*!
         * @brief Change name of weapon
         * @param _name name of weapon
         */
        void setName(std::string _name) { name = std::move(_name); }

        /*!
         * @brief Change name of ammunition
         * @param _name name of ammunition
         */
        void setAmmunitionName(std::string _name) { ammunitionName = std::move(_name); }

        /*!
         * @brief Change number of rate
         * @param rate
         */
        void setRateOfFire(uint rate);

        /*!
         * @brief Change number of ammunition
         * @param ammunition
         */
        void setAmmunition(uint ammunition);

        /*!
         * @brief Change number of destruction
         * @param destruction
         */
        void setDestruction(uint destruction);

        /*!
         * @brief Change type of weapon
         * @param type
         */
        void setType(typeOfWeapon type);

        /*!
         * @brief Compare two weapon
         * @param weapon
         * @return if weapons have equal all field they are equal and result is true, else false
         */
        bool operator == (const Weapon &weapon) const
        {
            if (this == &weapon)
                return true;
            return
                (name == weapon.name &&
                 ammunitionName == weapon.ammunitionName &&
                 rateOfFire == weapon.rateOfFire &&
                 ammunition == weapon.ammunition &&
                 destruction == weapon.destruction &&
                 type == weapon.type);
        }

        /*!
         * Put object of class Weapon in defined stream
         * @param weapon weapon who will be put in stream
         * @return
         */
        friend std::ostream& operator << (std::ostream &, const Weapon &weapon);

    };

    typedef std::vector<Weapon> vecWeapon;

}


#endif //LAB4_WEAPON_H
