#include <iostream>
#include "AppView.h"
#include "logic/Printed_Circuit_Board.h"
#include "logic/logic.h"

using namespace sf;

int main() {

    Lab3C::printedCircuitBoard _arduino;

    initializationPCB(_arduino);
    //std::cout << _arduino << std::endl;

    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(600, 300), "GeekON_by_Oleg_Krygin", styleParameter());
    std::vector<std::pair<CircleShape, int>> circles(getInput(_arduino));
    std::vector<std::pair<RectangleShape, int>> rectangles(getOutput(_arduino));
    std::cout << rectangles.size() << std::endl;
    initializationGObjects(window, circles, rectangles);
    initializationPairShape(_arduino, rectangles, circles);
    // Главный цикл приложения: выполняется, пока открыто окно
    while (window.isOpen())
    {
        processEvent(window, circles, rectangles);
        //Vector2i position = Mouse::getPosition();
    }

    window.close();
    return 0;
}
