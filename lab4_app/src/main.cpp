#include <Port.h>
#include "PointOnMap.h"
#include "GroupOfShips.h"
#include "Initialize.h"
#include "GameProcess.h"

int main()
{
    std::vector<Port> ports;
    std::vector<PointOnMap> points;
    lab4::GroupOfShips group;

    ports = initializePorts();
    group = initializeGroup();
    Port defaultPoint = ports[0];

    game_process(ports, group, defaultPoint);
    return 0;
}
