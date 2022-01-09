//
// Created by oleg on 08.01.2022.
//

#include <vector>
#include "GameProcess.h"


enum MenuAnswer {
    quit = 0,
    setCompound,
    selectPoint,
    startToMove,
    info
};

uint menu() {
    const char *menu_msgs[] =
            {
                    "1. Настроить состав",
                    "2. Выбрать пункт назначения",
                    "3. Отправиться в путь",
                    "4. Информация",
                    "0. Выход"
            };

    const uint size_menu_msgs = sizeof(menu_msgs) / sizeof(*menu_msgs);

    for(auto & menu_msg : menu_msgs)
        std::cout << menu_msg << std::endl;

    return size_menu_msgs;
}

int dialog(const uint &numOfStations)
{
    int rc;

    do {
        try{
            getNum(rc);
        } catch (const char err[]) {
            std::cout << "End of file" << std::endl;
            return 0;
        }
    } while(rc > numOfStations || rc < 0);

    return rc;
}

void game_process(const std::vector<PointOnMap> &points, lab4::GroupOfShips &group, const PointOnMap &startPoint)
{
    PointOnMap placeOfLocated = startPoint;
    group.setDeparturePoint(startPoint.getName());

    int rc;
    while ((rc = dialog(menu())) != quit)
    {
        if (rc == setCompound)
            ;//
        else if (rc == selectPoint)
            SelectPoint(points, group);
        else if (rc == startToMove)
            ;
        else if (rc == info)
            PutInformation(group, placeOfLocated);
    }
}