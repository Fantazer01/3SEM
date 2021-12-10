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

    ASSERT_EQ(1, group.getNumShipOfType(typeid(AircraftCarrier)));
    ASSERT_EQ(1, group.getNumShipOfType(typeid(Destroyer)));
}

TEST(GroupOfShips, Methods_setters_)
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

    AircraftCarrier air_ship2 = static_cast<AircraftCarrier&>(*(*table.find("lucky")).second);
    ASSERT_EQ(ship_AIRCRF, air_ship2);

    Destroyer dest_ship2 = static_cast<Destroyer&>(*(*table.find("bull")).second);
    ASSERT_EQ(destroyer, dest_ship2);
    ASSERT_EQ(group.end(), group.find("baby"));

    ASSERT_EQ(1, group.getNumShipOfType(typeid(AircraftCarrier)));
    ASSERT_EQ(1, group.getNumShipOfType(typeid(Destroyer)));
}

TEST(GroupOfShips, movePlane)
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
    AircraftCarrier ship_AIRCRF2("Big ship", set_smbds[2], 15, 100, 7, weapons_light);

    TableOfShips table;
    table.insert("lucky", &ship_AIRCRF);
    table.insert("bull", &ship_AIRCRF2);
    //end of initialization
    GroupOfShips group(table, set_smbds[0], "New Delly", "San-Francisco", 12345.8);

    ASSERT_EQ(2, dynamic_cast<AircraftCarrier&>(*(*(group.find("lucky"))).second).getNumPlanes());
    ASSERT_EQ(0, dynamic_cast<AircraftCarrier&>(*(*(group.find("bull"))).second).getNumPlanes());

    group.movePlane(dynamic_cast<AircraftCarrier&>(*(*(group.find("lucky"))).second).beginForPlane(), group.find("lucky"), group.find("bull"));

    ASSERT_EQ(1, dynamic_cast<AircraftCarrier&>(*(*(group.find("lucky"))).second).getNumPlanes());
    ASSERT_EQ(1, dynamic_cast<AircraftCarrier&>(*(*(group.find("bull"))).second).getNumPlanes());
}
/*
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

    AircraftCarrier ship_AIRCRF("Big ship", set_smbds[1], 15, 1000, 7, weapons_light, planes);
    Destroyer destroyer("Big ship", set_smbds[2], 15, 1300, 7, weapons_light_and_hard);

    TableOfShips table;
    table.insert("lucky", &ship_AIRCRF);
    table.insert("bull", &destroyer);
    //end of initialization
    GroupOfShips group(table, set_smbds[0], "New Delly", "San-Francisco", 12345.8);

    //begin of initialization: enemy
    vecPlane planes_enemy = {
            Plane(weapons_light, 15, 100, 20, Plane::fighter),
            Plane(weapons_light_and_hard, 17, 100, 23, Plane::bomber)
    };
    //end of initialization: enemy
    ASSERT_EQ(fight_over, group.modeling(planes_enemy));
}
*/
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
