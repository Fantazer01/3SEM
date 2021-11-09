//
// Created by oleg on 05.11.2021.
//

#include "AppView.h"
#include <iostream>

sf::Uint32 styleParameter() {
    return sf::Style::Titlebar+sf::Style::Close;
}

void initializationGObjects(sf::RenderWindow &window, std::vector<sf::CircleShape> &circles, std::vector<sf::RectangleShape> &rectangles) {
    window.setPosition(sf::Vector2<int>(400, 220));

    double radius = 25.f;
    double thickness = 10.f;
    int x = 0, y = 35, m = (window.getSize().x/circles.size() - 2*(radius+thickness))/2;

    for (sf::CircleShape &circle : circles) {
        x += m;
        circle.setRadius(radius);
        circle.setOutlineThickness(thickness);
        circle.setOutlineColor(sf::Color(130, 51, 51));
        circle.move(x, y);

        x += m + 2*(radius+thickness);
    }

    double weight = 2*(radius+thickness);
    double height = 40.f;
    x = 0;
    y = 220;
    m = (window.getSize().x/rectangles.size() - weight)/2;

    for (sf::RectangleShape &rectangle : rectangles) {
        x += m;
        rectangle.setSize(sf::Vector2f(weight,height));
        rectangle.setFillColor(sf::Color(71, 71, 204));
        rectangle.setOutlineThickness(7);
        rectangle.setOutlineColor(sf::Color(0,0,0,0));
        rectangle.move(x, y);
        x += m + weight;
    }
}

sf::Vector2i normalizationPositionMouse(sf::RenderWindow &window) {
    sf::Vector2i positionOfMouse = sf::Mouse::getPosition();
    positionOfMouse.x -= window.getPosition().x;
    positionOfMouse.y -= window.getPosition().y + 30;
    return positionOfMouse;
}

bool pointBelongToRectangle(sf::Vector2i &posPoint, sf::RectangleShape &rect) {
    sf::Vector2i posRect = sf::Vector2i(rect.getPosition());
    sf::Vector2i sizeRest = sf::Vector2i(rect.getSize());
    bool result;

    result = posRect.x <= posPoint.x && posRect.x+sizeRest.x >= posPoint.x;
    result &= posRect.y <= posPoint.y && posRect.y+sizeRest.y >= posPoint.y;
    return result;
}

void processEvent(sf::RenderWindow &window, std::vector<sf::CircleShape> &circles, std::vector<sf::RectangleShape> &rectangles) {
    using namespace sf;
    // Обрабатываем очередь событий в цикле
    int i = 0;
    Event event;
    while (window.pollEvent(event))
    {
        // Пользователь нажал на «крестик» и хочет закрыть окно?
        if (event.type == Event::Closed)
            window.close(); // тогда закрываем его

        if (event.type == Event::MouseButtonPressed) {
            Vector2i positionOfMouse = normalizationPositionMouse(window);
            for (RectangleShape &rectangle : rectangles) {
                if (pointBelongToRectangle(positionOfMouse, rectangle))
                    rectangle.setOutlineColor(sf::Color(255, 54, 101, 100));
            }
        } else {
            for (RectangleShape &rectangle : rectangles)
                rectangle.setOutlineColor(sf::Color(0,0,0, 0));
        }
    }
    // Установка цвета фона
    window.clear(Color(181, 181, 181, 0));

    // Закрашиваем наш круг
    for (CircleShape &circle : circles) {
        circle.setFillColor(Color(239, 169, 31));
        window.draw(circle);
    }

    for (sf::RectangleShape &rectangle : rectangles) {
        window.draw(rectangle);
    }

    // Отрисовка окна
    window.display();
}

namespace sf {

}
