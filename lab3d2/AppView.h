#include <SFML/Graphics.hpp>
#include "logic/Printed_Circuit_Board.h"

sf::Uint32 styleParameter();

using namespace sf;

void introduction();

void initializationGObjects(RenderWindow &window, std::vector<std::pair<CircleShape, int>> &circles, std::vector<std::pair<RectangleShape, int>> &rectangles);
void processEvent(RenderWindow &window, std::vector<std::pair<CircleShape, int>> &circles, std::vector<std::pair<RectangleShape, int>> &rectangles, Lab3C::printedCircuitBoard &_arduino);
