//
// Created by oleg on 12.11.2021.
//

#include "gtest/gtest.h"
#include "Ship.h"

using namespace lab4;

TEST(Ship, Constructor)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapon = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Ship ship("Big ship", smbd, 15, 100, 7, weapon);

    ASSERT_EQ("Big ship", ship.getName());
    ASSERT_EQ(smbd, ship.getInfoCaptain());
    ASSERT_EQ(15, ship.getSpeed());
    ASSERT_EQ(100, ship.getVitality());
    ASSERT_EQ(7, ship.getTeamMembers());

    std::vector<Weapon> weapon_result = ship.getArmament();
    std::vector<Weapon>::const_iterator it1, it2;
    ASSERT_EQ(weapon.size(), weapon_result.size());
    for (it1 = weapon.cbegin(), it2 = weapon_result.cbegin(); it1 != weapon.cend() && it2 != weapon_result.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);


}

TEST(Ship, Modificate)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapon = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Ship ship;

    ship.setName("Big ship");
    ship.setInfoCaptain(smbd);
    ship.setSpeed(15);
    ship.setVitality(100);
    ship.setTeamMembers(7);
    ship.setArmament(weapon);

    ASSERT_EQ("Big ship", ship.getName());
    ASSERT_EQ(smbd, ship.getInfoCaptain());
    ASSERT_EQ(15, ship.getSpeed());
    ASSERT_EQ(100, ship.getVitality());
    ASSERT_EQ(7, ship.getTeamMembers());

    std::vector<Weapon> weapon_result = ship.getArmament();
    std::vector<Weapon>::const_iterator it1, it2;
    ASSERT_EQ(weapon.size(), weapon_result.size());
    for (it1 = weapon.cbegin(), it2 = weapon_result.cbegin(); it1 != weapon.cend() && it2 != weapon_result.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);
}

TEST(Ship, WeaponMethods)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Ship ship("Big ship", smbd, 15, 100, 7, weapons);

    ASSERT_EQ(1, ship.getNumWeapon());

    weapons.push_back(Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10));
    ship.addWeapon(Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10));
    ASSERT_EQ(2, ship.getNumWeapon());

    std::vector<Weapon>::const_iterator it1, it2;
    for (it1 = ship.beginForWeapon(), it2 = weapons.cbegin(); it1 != ship.endForWeapon() && it2 != weapons.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);

    weapons[0].setDestruction(10000);
    ship.changeWeapon(weapons[0], ship.beginForWeapon());

    for (it1 = ship.beginForWeapon(), it2 = weapons.cbegin(); it1 != ship.endForWeapon() && it2 != weapons.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);

    ASSERT_EQ(10000, ship.calculateDamage(Target::air));
    ASSERT_EQ(10, ship.calculateDamage(Target::earth));
}

TEST(Ship, maxDistance)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Ship ship("Big ship", smbd, 15, 100, 7, weapons);

    ASSERT_EQ(100.0, ship.maxDistance(10));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
