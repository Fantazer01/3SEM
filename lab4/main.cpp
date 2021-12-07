#include <iostream>
#include "Person.h"
#include "Weapon.h"
#include "Plane.h"
#include "Ship.h"

int main() {
    using namespace lab4;

    FullName name = { "Best", "Proper", "Dear"};
    Person MrProper(std::string("Mr"), name, 35);
    std::cout << MrProper << std::endl;

    Weapon one("pushka", "pulki", Weapon::light, 5, 5, 5);
    std::cout << one;
    Plane plane;
    Ship ship("Lucky", MrProper, 5, 10, 15);
    ship.print(std::cout);
    return 0;
}
