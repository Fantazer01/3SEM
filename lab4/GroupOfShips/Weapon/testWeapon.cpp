//
// Created by oleg on 11.11.2021.
//


#include "gtest/gtest.h"
#include "Weapon.h"

using namespace lab4;

TEST(Weapon, Constructor)
{
    Weapon weapon("aka", "bullet", Weapon::light, 5, 6, 7);

    ASSERT_EQ("aka", weapon.getName());
    ASSERT_EQ("bullet", weapon.getAmmunitionName());
    ASSERT_EQ(Weapon::light, weapon.getType());
    ASSERT_EQ(5, weapon.getRateOfFire());
    ASSERT_EQ(6, weapon.getAmmunition());
    ASSERT_EQ(7, weapon.getDestruction());
}

TEST(Weapon, Modificate)
{
    Weapon weapon;

    weapon.setName("aka");
    weapon.setAmmunitionName("bullet");
    weapon.setType(Weapon::light);
    weapon.setRateOfFire(5);
    weapon.setAmmunition(6);
    weapon.setDestruction(7);

    ASSERT_EQ("aka", weapon.getName());
    ASSERT_EQ("bullet", weapon.getAmmunitionName());
    ASSERT_EQ(Weapon::light, weapon.getType());
    ASSERT_EQ(5, weapon.getRateOfFire());
    ASSERT_EQ(6, weapon.getAmmunition());
    ASSERT_EQ(7, weapon.getDestruction());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
