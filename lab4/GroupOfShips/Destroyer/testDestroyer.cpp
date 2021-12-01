//
// Created by oleg on 01.12.2021.
//

#include "gtest/gtest.h"
#include "Destroyer.h"

using namespace lab4;

TEST(Destroyer, Constructor)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Ship ship("Big ship", smbd, 15, 100, 7, weapons);

    Destroyer destroyer("Big ship", smbd, 15, 100, 7, weapons, &ship);

    ASSERT_EQ(&ship, destroyer.getCovered());
}

TEST(Destroyer, Modificate)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Ship ship("Big ship", smbd, 15, 100, 7, weapons);

    Destroyer destroyer("Big ship", smbd, 15, 100, 7, weapons);

    destroyer.setCovered(&ship);

    ASSERT_EQ(&ship, destroyer.getCovered());
}

TEST(Destroyer, maxDistance)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    Destroyer ship("Big ship", smbd, 15, 100, 7, weapons);

    ASSERT_EQ(110.0, ship.maxDistance(10));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
