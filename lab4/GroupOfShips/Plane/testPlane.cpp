//
// Created by oleg on 11.11.2021.
//

#include "gtest/gtest.h"
#include "Plane.h"

using namespace lab4;

TEST(Plane, Constructors)
{
    std::vector<Weapon> weapon = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Plane plane(weapon, 50, 100, 20, Plane::bomber);

    std::vector<Weapon> weapon_result = plane.getArmament();
    std::vector<Weapon>::const_iterator it1, it2;
    ASSERT_EQ(weapon.size(), weapon_result.size());
    for (it1 = weapon.cbegin(), it2 = weapon_result.cbegin(); it1 != weapon.cend() && it2 != weapon_result.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);

    ASSERT_EQ(50, plane.getSpeed());
    ASSERT_EQ(100, plane.getVitality());
    ASSERT_EQ(20, plane.getFuelConsumption());
    ASSERT_EQ(Plane::bomber, plane.getType());
}

TEST(Plane, Modificate)
{
    std::vector<Weapon> weapon = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Plane plane;

    plane.setType(Plane::bomber);
    plane.setArmament(weapon);
    plane.setSpeed(50);
    plane.setVitality(100);
    plane.setFuelConsumption(20);

    std::vector<Weapon> weapon_result = plane.getArmament();
    std::vector<Weapon>::const_iterator it1, it2;
    ASSERT_EQ(weapon.size(), weapon_result.size());
    for (it1 = weapon.cbegin(), it2 = weapon_result.cbegin(); it1 != weapon.cend() && it2 != weapon_result.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);

    ASSERT_EQ(50, plane.getSpeed());
    ASSERT_EQ(100, plane.getVitality());
    ASSERT_EQ(20, plane.getFuelConsumption());
    ASSERT_EQ(Plane::bomber, plane.getType());
}

TEST(Plane, MethodsWeapon)
{
    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Plane plane(weapons, 50, 100, 20, Plane::bomber);

    ASSERT_EQ(1, plane.getNumWeapon());

    weapons.push_back(Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10));
    plane.addWeapon(Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10));
    ASSERT_EQ(2, plane.getNumWeapon());

    std::vector<Weapon>::const_iterator it1, it2;
    for (it1 = plane.begin(), it2 = weapons.cbegin(); it1 != plane.end() && it2 != weapons.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);

    weapons[0].setDestruction(10000);
    plane.changeWeapon(weapons[0], plane.begin());

    for (it1 = plane.begin(), it2 = weapons.cbegin(); it1 != plane.end() && it2 != weapons.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);

    ASSERT_EQ(10000, plane.calculateDamage(Target::air));
    ASSERT_EQ(10, plane.calculateDamage(Target::earth));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
