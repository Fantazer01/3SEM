//
// Created by oleg on 08.01.2022.
//

#include "GameProcess.h"


using namespace lab4;

void PutListPorts(const std::vector<Port> &points)
{
    std::cout << "List of Points:" << std::endl;
    int i = 0;
    for (auto point = points.cbegin(); point != points.cend(); ++point, ++i) {
        std::cout << i << " " << point->getName()
                  << " (" << point->get1stCoordinate() << ", " << point->get2ndCoordinate() << ") " << std::endl;
    }
}

uint SelectPoint(const std::vector<Port> &points, lab4::GroupOfShips &group)
{
    PutListPorts(points);
    std::cout << "You are in " << group.getDeparturePoint() << std::endl;

    uint rc;

    rc = dialog(points.size());
    if (points[rc].getName() != group.getDeparturePoint())
    {
        std::cout << "You are just here" << std::endl;
    } else
    {
        group.setPointOfArrival(points[rc].getName());
        std::cout << "Changing is success" << std::endl;
    }
    return rc;
}