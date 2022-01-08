#include "PointOnMap.h"
#include "GroupOfShips.h"
#include "Initialize.h"
#include "GameProcess.h"

int main()
{
    std::vector<PointOnMap> points;
    lab4::GroupOfShips group;

    points = initializePoints();
    group = initializeGroup();
    PointOnMap defaultPoint = points[0];

    game_process(points, group, defaultPoint);
    return 0;
}
