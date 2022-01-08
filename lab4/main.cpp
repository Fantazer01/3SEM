#include <iostream>
#include "Person.h"
#include "Weapon.h"
#include "Plane.h"
#include "Ship.h"
#include "GroupOfShips.h"

using namespace lab4;

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

int main() {


    lab4::GroupOfShips group;
    group = initializeGroup();
    /*
    FullName name = { "Best", "Proper", "Dear"};
    Person MrProper(std::string("Mr"), name, 35);
    std::cout << MrProper << std::endl;

    Weapon one("pushka", "pulki", Weapon::light, 5, 5, 5);
    std::cout << one;
    Plane plane;
    Ship ship("Lucky", MrProper, 5, 10, 15);

    ship.print(std::cout);
     */
    group.print(std::cout);
    return 0;
}
