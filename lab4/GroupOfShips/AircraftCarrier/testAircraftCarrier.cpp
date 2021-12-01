//
// Created by oleg on 01.12.2021.
//

#include "gtest/gtest.h"
#include "AircraftCarrier.h"

using namespace lab4;

TEST(AircraftCarrier, Constructor)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapon = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };
    std::vector<Plane> planes = {
            Plane(weapon, 15, 100, 20, Plane::fighter)
    };

    AircraftCarrier ship("Big ship", smbd, 15, 100, 7, weapon, planes);

    std::vector<Plane> planes_result = ship.getPlanes();
    std::vector<Plane>::const_iterator it1, it2;
    ASSERT_EQ(planes.size(), planes_result.size());
    for (it1 = planes.cbegin(), it2 = planes_result.cbegin(); it1 != planes.cend() && it2 != planes_result.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);
}

TEST(AircraftCarrier, Modificate)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapon = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };
    std::vector<Plane> planes = {
            Plane(weapon, 15, 100, 20, Plane::fighter)
    };

    AircraftCarrier ship("Big ship", smbd, 15, 100, 7, weapon);

    ship.setPlanes(planes);

    std::vector<Plane> planes_result = ship.getPlanes();
    std::vector<Plane>::const_iterator it1, it2;
    ASSERT_EQ(planes.size(), planes_result.size());
    for (it1 = planes.cbegin(), it2 = planes_result.cbegin(); it1 != planes.cend() && it2 != planes_result.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);
}

TEST(AircraftCarrier, PlaneMethods)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };
    std::vector<Plane> planes = {
            Plane(weapons, 15, 100, 20, Plane::fighter)
    };

    AircraftCarrier ship("Big ship", smbd, 15, 100, 7, weapons, planes);

    ASSERT_EQ(1, ship.getNumPlanes());

    weapons.push_back(Weapon("bazooka", "rocket", Weapon::heavy, 8, 9,10));
    planes.push_back(Plane(weapons, 17, 100, 23, Plane::bomber));
    ship.addPlane(planes[1]);
    ASSERT_EQ(2, ship.getNumPlanes());

    std::vector<Plane>::const_iterator it1, it2;
    for (it1 = ship.beginForPlane(), it2 = planes.cbegin(); it1 != ship.endForPlane() && it2 != planes.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);

    planes[0].setVitality(50);
    ship.changePlane(planes[0], ship.beginForPlane());

    for (it1 = ship.beginForPlane(), it2 = planes.cbegin(); it1 != ship.endForPlane() && it2 != planes.cend(); ++it1, ++it2)
        ASSERT_EQ(*it1, *it2);

    ASSERT_EQ(14, ship.calculateDamagePlanes(Target::air));
    ASSERT_EQ(10, ship.calculateDamagePlanes(Target::earth));
}

TEST(AircraftCarrier, maxDistance)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);
    std::vector<Weapon> weapons = {
            Weapon("aka", "bullet", Weapon::light, 5, 6, 7)
    };

    AircraftCarrier ship("Big ship", smbd, 15, 100, 7, weapons);

    ASSERT_EQ(80.0, ship.maxDistance(10));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

