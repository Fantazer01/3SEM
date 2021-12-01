//
// Created by oleg on 01.12.2021.
//

#include "gtest/gtest.h"
#include "AircraftCarrier.h"
#include "Destroyer.h"
#include "TableOfShips.h"

using namespace lab4;

TEST(TableOfShips, mainMethods)
{
    TableOfShips table;

    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);

    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    std::vector<Plane> planes = {
            Plane(weapons, 15, 100, 20, Plane::fighter),
            Plane(weapons, 17, 100, 23, Plane::bomber)
    };

    AircraftCarrier ship_AIRCRF("Big ship", smbd, 15, 100, 7, weapons, planes);
    Destroyer destroyer("Big ship", smbd, 15, 100, 7, weapons);

    table.insert("lucky", &ship_AIRCRF);
    table.insert("bull", &destroyer);

    ASSERT_EQ(2, table.getNumOfGroup());

    ASSERT_EQ(&ship_AIRCRF, (*table.find("lucky")).second);
    ASSERT_EQ(&destroyer, (*table.find("bull")).second);
    ASSERT_EQ(table.end(), table.find("baby"));

    table.erase(table.find("lucky"));

    ASSERT_EQ(table.end(), table.find("lucky"));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}