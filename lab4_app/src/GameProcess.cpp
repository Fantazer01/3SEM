//
// Created by oleg on 08.01.2022.
//

#include <vector>
#include "PointOnMap.h"
#include "GroupOfShips.h"
#include "GameProcess.h"
#include "LabTools.h"

enum MenuAnswer {
    quit = 0,
    setCompound,
    selectPoint,
    startToMove,
    info
};

int menu() {
    const char *menu_msgs[] =
            {
                    "1. Настроить состав",
                    "2. Выбрать пункт назначения",
                    "3. Отправиться в путь",
                    "4. Информация",
                    "0. Выход"
            };

    const int size_menu_msgs = sizeof(menu_msgs) / sizeof(*menu_msgs);

    for(auto & menu_msg : menu_msgs)
        std::cout << menu_msg << std::endl;

    return size_menu_msgs;
}

int dialog() {
    int numOfStations, rc;

    numOfStations = menu();

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
    int rc = 0;
    while ((rc = dialog()) != quit)
    {
        if (rc == setCompound)
            ;//
        else if (rc == selectPoint)
            ;//
        else if (rc == startToMove)
            ;
        else if (rc == info)
            PutInformation(group, placeOfLocated);
    }
}