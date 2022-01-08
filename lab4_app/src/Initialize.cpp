//
// Created by oleg on 08.01.2022.
//

#include "Initialize.h"

using namespace lab4;

std::vector<PointOnMap> initializePoints()
{
    std::vector<PointOnMap> points =
    {
            PointOnMap("New York", 23, 105),
            PointOnMap("Paramaribo", 46, 33),
            PointOnMap("Lisbon", 149, 58)
    };

    return points;
}

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

vecPlane initPlanesEnemy(const std::vector<Weapon> &weapons_light, const std::vector<Weapon> &weapons_light_and_hard)
{
    vecPlane planes = {
            Plane(weapons_light, 15, 100, 20, Plane::fighter),
            Plane(weapons_light_and_hard, 17, 100, 23, Plane::bomber)
    };
    return planes;
}

lab4::GroupOfShips initializeGroup()
{
    std::vector<Person> set_smbds = arrayPerson();
    vecWeapon weapons_light = WeaponLight();
    vecWeapon weapons_light_and_hard = WeaponLightAndHard();
    vecPlane planes = initPlanes(weapons_light, weapons_light_and_hard);
    vecPlane planes_enemy = initPlanesEnemy(weapons_light, weapons_light_and_hard);

    AircraftCarrier ship_AIRCRF("AirCar", set_smbds[1], 15, 1000, 7, weapons_light, planes);
    Destroyer destroyer("Bambam", set_smbds[2], 15, 1300, 7, weapons_light_and_hard);

    GroupOfShips group(TableOfShips(), set_smbds[0], "", "", 0);
    group.insert("lucky", &ship_AIRCRF);
    group.insert("bull", &destroyer);

    return group;
}