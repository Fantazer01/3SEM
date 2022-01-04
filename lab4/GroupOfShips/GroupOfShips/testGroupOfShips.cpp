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

TEST(GroupOfShips, shipAiming_Destroyer)
{
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes_enemy = initPlanes(weapons_light, weapons_light_and_hard);

    Destroyer destroyer("Bambam", set_smbds[2], 15, 1300, 7, weapons_light_and_hard);

    Target_set target = createTarget(planes_enemy);
    Target_plane_it tar_planeIt = target.air.begin();

    shipAiming(&destroyer, target, tar_planeIt);

    tar_planeIt = target.air.begin();
    auto AnswerPlaneIt = planes_enemy.begin();

    ASSERT_EQ(*tar_planeIt->first, *AnswerPlaneIt);
    ASSERT_EQ(tar_planeIt->second, 7);

    ++tar_planeIt;
    ++AnswerPlaneIt;

    ASSERT_EQ(*tar_planeIt->first, *AnswerPlaneIt);
    ASSERT_EQ(tar_planeIt->second, 0);
}

TEST(GroupOfShips, shipAiming_AircraftCarrier) {
    std::vector<Person> set_smbds = arrayPerson();
    std::vector<Weapon> weapons_light = WeaponLight();
    std::vector<Weapon> weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);
    vecPlane planes_enemy = initPlanes(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 1000, 7, weapons_light, planes);

    Target_set target = createTarget(planes_enemy);
    Target_plane_it tar_planeIt = target.air.begin();

    shipAiming(&ship_AIRCRF, target, tar_planeIt);

    tar_planeIt = target.air.begin();
    auto AnswerPlaneIt = planes_enemy.begin();

    ASSERT_EQ(*tar_planeIt->first, *AnswerPlaneIt);
    ASSERT_EQ(tar_planeIt->second, 21);

    ++tar_planeIt;
    ++AnswerPlaneIt;

    ASSERT_EQ(*tar_planeIt->first, *AnswerPlaneIt);
    ASSERT_EQ(tar_planeIt->second, 0);
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

    Target_set target = createTarget(planes_enemy);

    groupAiming(target, group);

    Target_plane_it tar_planeIt = target.air.begin();
    auto AnswerPlaneIt = planes_enemy.begin();

    ASSERT_EQ(*tar_planeIt->first, *AnswerPlaneIt);
    ASSERT_EQ(tar_planeIt->second, 28);

    ++tar_planeIt;
    ++AnswerPlaneIt;

    ASSERT_EQ(*tar_planeIt->first, *AnswerPlaneIt);
    ASSERT_EQ(tar_planeIt->second, 0);
}

TEST(GroupOfShips, enemyAiming)
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

    Target_set target = createTarget(group);

    enemyAiming(target, planes_enemy);

    Target_plane_it tar_planeIt = target.air.begin();
    Target_ship_it tar_shipIt = target.earth.begin();
    auto plane_group_it = dynamic_cast<AircraftCarrier &>(*(*(group.find("lucky"))).second).beginForPlane();
    auto ship_group_it = group.begin();

    ASSERT_EQ(*tar_planeIt->first, *plane_group_it);
    ASSERT_EQ(tar_planeIt->second, 14);

    ASSERT_EQ(tar_shipIt->first, (*ship_group_it).second);
    ASSERT_EQ(tar_shipIt->second, 10);

    ++tar_planeIt;
    ++tar_shipIt;
    ++plane_group_it;
    ++ship_group_it;

    ASSERT_EQ(*tar_planeIt->first, *plane_group_it);
    ASSERT_EQ(tar_planeIt->second, 0);

    ASSERT_EQ(tar_shipIt->first, (*ship_group_it).second);
    ASSERT_EQ(tar_shipIt->second, 0);
}

TEST(GroupOfShips, stepOfFight)
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

    group.stepOfFight(planes_enemy);

    auto plane_enemy_it = planes_enemy.begin();
    auto plane_group_it = dynamic_cast<AircraftCarrier &>(*(*(group.find("lucky"))).second).beginForPlane();
    auto ship_group_it = group.begin();

    ASSERT_EQ(72, plane_enemy_it->getVitality());
    ASSERT_EQ(86, plane_group_it->getVitality());
    ASSERT_EQ(1290, (*ship_group_it).second->getVitality());

    ++plane_enemy_it;
    ++plane_group_it;
    ++ship_group_it;

    ASSERT_EQ(100, plane_enemy_it->getVitality());
    ASSERT_EQ(100, plane_group_it->getVitality());
    ASSERT_EQ(1000, (*ship_group_it).second->getVitality());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
