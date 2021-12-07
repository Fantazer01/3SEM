//
// Created by oleg on 02.12.2021.
//

#include "gtest/gtest.h"
#include "AircraftCarrier.h"
#include "Destroyer.h"
#include "GroupOfShips.h"

using namespace lab4;

TEST(GroupOfShips, Constructor)
{
    //begin of initialization
    Person set_smbds[] = {
            Person("boss", { "Simpson", "Tom", "Ivanovich"}, 15),
            Person("minion", { "Pines", "Jo", "Petrovich"}, 6),
            Person("hunky", { "Trump", "Peter", "Mikhailovich"}, 11)
    };

    std::vector<Weapon> weapons_light = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    std::vector<Weapon> weapons_light_and_hard = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7),
            Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10)
    };

    vecPlane planes = {
            Plane(weapons_light, 15, 100, 20, Plane::fighter),
            Plane(weapons_light_and_hard, 17, 100, 23, Plane::bomber)
    };

    AircraftCarrier ship_AIRCRF("Big ship", set_smbds[1], 15, 100, 7, weapons_light, planes);
    Destroyer destroyer("Big ship", set_smbds[2], 15, 100, 7, weapons_light_and_hard);

    TableOfShips table;
    table.insert("lucky", &ship_AIRCRF);
    table.insert("bull", &destroyer);
    //end of initialization
    GroupOfShips group(table, set_smbds[0], "New Delly", "San-Francisco", 12345.8);

    ASSERT_EQ(set_smbds[0], group.getCommander());
    ASSERT_EQ("New Delly", group.getDeparturePoint());
    ASSERT_EQ("San-Francisco", group.getPointOfArrival());
    ASSERT_EQ(12345.8, group.getDistance());

    ASSERT_EQ(2, group.getNumOfGroup());

    ASSERT_EQ(&ship_AIRCRF, (*group.find("lucky")).second);
    ASSERT_EQ(&destroyer, (*group.find("bull")).second);
    ASSERT_EQ(group.end(), group.find("baby"));
}

TEST(GroupOfShips, Methods)
{
    //begin of initialization
    Person set_smbds[] = {
            Person("boss", { "Simpson", "Tom", "Ivanovich"}, 15),
            Person("minion", { "Pines", "Jo", "Petrovich"}, 6),
            Person("hunky", { "Trump", "Peter", "Mikhailovich"}, 11)
    };

    std::vector<Weapon> weapons_light = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    std::vector<Weapon> weapons_light_and_hard = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7),
            Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10)
    };

    vecPlane planes = {
            Plane(weapons_light, 15, 100, 20, Plane::fighter),
            Plane(weapons_light_and_hard, 17, 100, 23, Plane::bomber)
    };

    AircraftCarrier ship_AIRCRF("Big ship", set_smbds[1], 15, 100, 7, weapons_light, planes);
    Destroyer destroyer("Big ship", set_smbds[2], 15, 100, 7, weapons_light_and_hard);

    TableOfShips table;
    table.insert("lucky", &ship_AIRCRF);
    table.insert("bull", &destroyer);
    //end of initialization
    GroupOfShips group;

    group.setTable(table);
    group.setCommander(set_smbds[0]);
    group.setDeparturePoint("New Delly");
    group.setPointOfArrival("San-Francisco");
    group.setDistance(12345.8);

    ASSERT_EQ(set_smbds[0], group.getCommander());
    ASSERT_EQ("New Delly", group.getDeparturePoint());
    ASSERT_EQ("San-Francisco", group.getPointOfArrival());
    ASSERT_EQ(12345.8, group.getDistance());

    ASSERT_EQ(2, group.getNumOfGroup());

    ASSERT_EQ(&ship_AIRCRF, (*group.find("lucky")).second);
    ASSERT_EQ(&destroyer, (*group.find("bull")).second);
    ASSERT_EQ(group.end(), group.find("baby"));
}

TEST(GroupOfShips, Modeling)
{
    //begin of initialization
    Person set_smbds[] = {
            Person("boss", { "Simpson", "Tom", "Ivanovich"}, 15),
            Person("minion", { "Pines", "Jo", "Petrovich"}, 6),
            Person("hunky", { "Trump", "Peter", "Mikhailovich"}, 11)
    };

    std::vector<Weapon> weapons_light = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    std::vector<Weapon> weapons_light_and_hard = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7),
            Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10)
    };

    vecPlane planes = {
            Plane(weapons_light, 15, 100, 20, Plane::fighter),
            Plane(weapons_light_and_hard, 17, 100, 23, Plane::bomber)
    };

    AircraftCarrier ship_AIRCRF("Big ship", set_smbds[1], 15, 100, 7, weapons_light, planes);
    Destroyer destroyer("Big ship", set_smbds[2], 15, 100, 7, weapons_light_and_hard);

    TableOfShips table;
    table.insert("lucky", &ship_AIRCRF);
    table.insert("bull", &destroyer);
    //end of initialization
    GroupOfShips group(table, set_smbds[0], "New Delly", "San-Francisco", 12345.8);

    //begin of initialization: enemy
    std::vector<Plane> planes_enemy = {
            Plane(weapons_light, 15, 100, 20, Plane::fighter),
            Plane(weapons_light_and_hard, 17, 100, 23, Plane::bomber)
    };
    //end of initialization: enemy
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
