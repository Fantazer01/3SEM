#include <SFML/Graphics.hpp>

sf::Uint32 styleParameter();

using namespace sf;

void initializationGObjects(RenderWindow &window, std::vector<std::pair<CircleShape, int>> &circles, std::vector<std::pair<RectangleShape, int>> &rectangles);
void processEvent(RenderWindow &window, std::vector<std::pair<CircleShape, int>> &circles, std::vector<std::pair<RectangleShape, int>> &rectangles);
