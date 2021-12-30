//
// Created by oleg on 02.12.2021.
//

#include "gtest/gtest.h"
#include "AircraftCarrier.h"
#include "Destroyer.h"
#include "GroupOfShips.h"

using namespace lab4;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~data~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
std::vector<Person> arrayPerson()
{
    std::vector<Person> people = {
            Person("boss", { "Simpson", "Tom", "Ivanovich"}, 15),
            Person("minion", { "Pines", "Jo", "Petrovich"}, 6),
            Person("hunky", { "Trump", "Peter", "Mikhailovich"}, 11)
    };
    return people;
}

std::vector<Weapon> WeaponLight()
{
    std::vector<Weapon> weapons_light = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };
    return weapons_light;
}

std::vector<Weapon> WeaponLightAndHard()
{
    std::vector<Weapon> weapons_light_and_hard = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7),
            Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10)
    };
    return weapons_light_and_hard;
}

vecPlane initPlanes(const std::vector<Weapon> &weapons_light, const std::vector<Weapon> &weapons_light_and_hard)
{
    vecPlane planes = {
            Plane(weapons_light, 15, 100, 20, Plane::fighter),
            Plane(weapons_light_and_hard, 17, 100, 23, Plane::bomber)
    };
    return planes;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~end-of-data~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TEST(GroupOfShips, Constructor)
{
    //begin of initialization
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 100, 7, weapons_light, planes);
    Destroyer destroyer("Bambam", set_smbds[2], 15, 100, 7, weapons_light_and_hard);

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

    ASSERT_EQ(true, (*group.find("lucky")).second->equal(&ship_AIRCRF));
    ASSERT_EQ(true, (*group.find("bull")).second->equal(&destroyer));
    ASSERT_EQ(group.end(), group.find("baby"));

    ASSERT_EQ(1, group.getNumShipOfType(typeid(AircraftCarrier)));
    ASSERT_EQ(1, group.getNumShipOfType(typeid(Destroyer)));
}

TEST(GroupOfShips, Methods_setters_)
{
    //begin of initialization
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 100, 7, weapons_light, planes);
    Destroyer destroyer("Bambam", set_smbds[2], 15, 100, 7, weapons_light_and_hard);

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

    AircraftCarrier air_ship2 = dynamic_cast<AircraftCarrier&>(*(*table.find("lucky")).second);
    ASSERT_EQ(ship_AIRCRF, air_ship2);

    Destroyer dest_ship2 = dynamic_cast<Destroyer&>(*(*table.find("bull")).second);
    ASSERT_EQ(destroyer, dest_ship2);
    ASSERT_EQ(group.end(), group.find("baby"));

    ASSERT_EQ(1, group.getNumShipOfType(typeid(AircraftCarrier)));
    ASSERT_EQ(1, group.getNumShipOfType(typeid(Destroyer)));
}

TEST(GroupOfShips, movePlane)
{
    //begin of initialization
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 100, 7, weapons_light, planes);
    AircraftCarrier ship_AIRCRF2("Bambam", set_smbds[2], 15, 100, 7, weapons_light);

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
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 1000, 7, weapons_light, planes);
    Destroyer destroyer("Bambam", set_smbds[2], 15, 1300, 7, weapons_light_and_hard);

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

TEST(GroupOfShips, StepOfFight)
{
    //begin of initialization
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 1000, 7, weapons_light, planes);
    Destroyer destroyer("Bambam", set_smbds[2], 15, 1300, 7, weapons_light_and_hard);

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

    group.stepOfFight(planes_enemy);
    std::cout << "test#####################################\n";
    /*for (auto a : group) {
        std::cout << "Ship:\n";
        std::cout << *(a.second) << "\n\n";
    }
    for (const auto &a : planes_enemy) {
        std::cout << "Plane:\n";
        std::cout << a << "\n\n";
    }

}*/

std::list<Plane *> createPointerList(vecPlane &planes_enemy)
{
    std::list<Plane *> enemy_aircraft_pointer(planes_enemy.size());
    auto it = planes_enemy.begin();
    auto it_p = enemy_aircraft_pointer.begin();
    for (; it != planes_enemy.end(); ++it, ++it_p)
        *it_p = &(*it);
    return enemy_aircraft_pointer;
}

TEST(GroupOfShips, step_change_target_for_group)
{
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes_enemy = initPlanes(weapons_light, weapons_light_and_hard);

    Target_set target;

    std::list<Plane *> enemy_aircraft_pointer = createPointerList(planes_enemy);

    step_change_target_for_group(enemy_aircraft_pointer, target);

    ASSERT_EQ(false, target.air.empty());
    ASSERT_EQ(*(target.air.begin()->first), (*planes_enemy.begin()));
    ASSERT_EQ(target.air.begin()->second, 0);
    ASSERT_EQ(enemy_aircraft_pointer.size(), 1);
}

TEST(GroupOfShips, shipAiming_Destroyer)
{
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes_enemy = initPlanes(weapons_light, weapons_light_and_hard);

    Destroyer destroyer("Bambam", set_smbds[2], 15, 1300, 7, weapons_light_and_hard);

    Target_set target;

    std::list<Plane *> enemy_aircraft_pointer;
    enemy_aircraft_pointer = createPointerList(planes_enemy);

    shipAiming(enemy_aircraft_pointer, &destroyer, target);

    ASSERT_EQ(target.air.size(), 1);
    ASSERT_EQ(target.air.begin()->second, 7);
}

TEST(GroupOfShips, shipAiming_AircraftCarrier)
{
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);
    vecPlane planes_enemy = initPlanes(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 1000, 7, weapons_light, planes);

    Target_set target;

    std::list<Plane *> enemy_aircraft_pointer;
    enemy_aircraft_pointer = createPointerList(planes_enemy);

    shipAiming(enemy_aircraft_pointer, &ship_AIRCRF, target);

    ASSERT_EQ(target.air.size(), 1);
    ASSERT_EQ(target.air.begin()->second, 21);
}

TEST(GroupOfShips, groupAiming)
{
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);
    vecPlane planes_enemy = initPlanes(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 1000, 7, weapons_light, planes);
    Destroyer destroyer("Bambam", set_smbds[2], 15, 1300, 7, weapons_light_and_hard);

    GroupOfShips group(TableOfShips(), set_smbds[0], "New Delly", "San-Francisco", 12345.8);
    group.insert("lucky", &ship_AIRCRF);
    group.insert("bull", &destroyer);

    Target_set target;

    std::list<Plane *> enemy_aircraft_pointer;
    enemy_aircraft_pointer = createPointerList(planes_enemy);

    target = groupAiming(enemy_aircraft_pointer, group);

    ASSERT_EQ(target.air.size(), 1);
    ASSERT_EQ(target.air.begin()->second, 28);
}
/*
TEST(GroupOfShips, FuncOfFight)
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

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 1000, 7, weapons_light, planes);
    Destroyer destroyer("Bambam", set_smbds[2], 15, 1300, 7, weapons_light_and_hard);

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

    Target_set target_group;// = groupAiming(planes_enemy, group);
    shipAiming(planes_enemy, (*group.begin()).second, target_group);
    ASSERT_EQ(*(target_group.air.begin()->first), *(planes_enemy.begin()));

}*/

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
