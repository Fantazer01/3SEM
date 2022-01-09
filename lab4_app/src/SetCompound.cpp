//
// Created by oleg on 09.01.2022.
//

#include "GameProcess.h"

uint SetCompoundMenu()
{
    const char *menu_msgs[] =
            {
                    "0. Переместить судно из группы в порт",
                    "1. Переместить судно из порта в группу",
            };

    const uint size_menu_msgs = sizeof(menu_msgs) / sizeof(*menu_msgs);

    for(auto & menu_msg : menu_msgs)
        std::cout << menu_msg << std::endl;

    return size_menu_msgs;
}

uint IsRepeat()
{
    const char *menu_msgs[] =
            {
                    "0. Завершить настройку состава",
                    "1. Желаю продолжить настройку состава",
            };

    const uint size_menu_msgs = sizeof(menu_msgs) / sizeof(*menu_msgs);

    for(auto & menu_msg : menu_msgs)
        std::cout << menu_msg << std::endl;

    return size_menu_msgs;
}

void MoveFromGroupToPort(GroupOfShips &group, Port &port)
{
    std::cout << "Введите позывной судна" << std::endl;

    std::string callSign;
    std::cin >> callSign;

    ship_iterator shipIt = group.find(callSign);

    if (shipIt == group.end())
    {
        std::cout << "Судно не найденно" << std::endl;
    } else
    {
        port.insert(shipIt->first, shipIt->second);
        group.erase(shipIt);
    }
}

void MoveFromPortToGroup(GroupOfShips &group, Port &port)
{
    std::cout << "Введите позывной судна" << std::endl;

    std::string callSign;
    std::cin >> callSign;

    ship_iterator shipIt = port.find(callSign);

    if (shipIt == port.end())
    {
        std::cout << "Судно не найденно" << std::endl;
    } else
    {
        group.insert(shipIt->first, shipIt->second);
        port.erase(shipIt);
    }
}

void SetCompound(GroupOfShips &group, Port &port)
{
    port.print(std::cout);
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    group.print(std::cout);

    do {
        uint rc = dialog(SetCompoundMenu());
        if (rc == 0)
            MoveFromGroupToPort(group, port);
        else
            MoveFromPortToGroup(group, port);
        std::cout << "Состояния модернизированных объектов" << std::endl;
        port.print(std::cout);
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        group.print(std::cout);
    } while (dialog(IsRepeat()) != 0);


}