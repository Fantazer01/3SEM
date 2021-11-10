#include <iostream>
#include "AppView.h"
#include "logic/Printed_Circuit_Board.h"
#include "logic/logic.h"

using namespace sf;

int main() {
    using namespace std;

    introduction();
    Lab3C::printedCircuitBoard _arduino;

    initializationPCB(_arduino);
    cout << _arduino << endl;
    setConnectPCB(_arduino);

    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(600, 300), "GeekON_by_Oleg_Krygin", styleParameter());
    vector<pair<CircleShape, int>> circles(getInput(_arduino));
    vector<pair<RectangleShape, int>> rectangles(getOutput(_arduino));

    initializationGObjects(window, circles, rectangles);
    initializationPairShape(_arduino, rectangles, circles);
    // Главный цикл приложения: выполняется, пока открыто окно
    while (window.isOpen())
    {
        processEvent(window, circles, rectangles, _arduino);
    }

    window.close();
    return 0;
}
