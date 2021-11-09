#include <SFML/Graphics.hpp>

sf::Uint32 styleParameter();

void initializationGObjects(sf::RenderWindow &window, std::vector<sf::CircleShape> &circles, std::vector<std::pair<sf::RectangleShape, int>> &rectangles);
void processEvent(sf::RenderWindow &window, std::vector<sf::CircleShape> &circles, std::vector<std::pair<sf::RectangleShape, int>> &rectangles);
