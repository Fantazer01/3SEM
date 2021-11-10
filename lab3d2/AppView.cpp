//
// Created by oleg on 05.11.2021.
//

#include "AppView.h"
#include <iostream>

void introduction() {
    system("clear");
    std::cout << "\n"
              << "                  $$$$\n"
                 "                 $$$$$$$\n"
                 "                 $$$$$$$$    $_$_$\n"
                 "                  $$$$$$$   $$$$$$\n"
                 "                   $$$$$     $$$\n"
                 "                     $$$$$$$$$$\n"
                 "           $___$_$    $$$$$$$\n"
                 "            $$$$$$   $$$$$$$\n"
                 "             $$$ $$$$$$$$$$$$\n"
                 "                      $$$$$$$$\n"
                 "                      $$$$$$$$\n"
                 "                       $$$$$$$$$$$$\n"
                 "                    $$$$$$$$$$   $$$\n"
                 "                    $$$$  $$$$$   $$$$\n"
                 "                    $$$    $$$$$  $ $ $\n"
                 "                   $ $ $   $$$$$\n"
                 "                            $$$$\n"
                 "                   $$$$$    $$$\n"
                 "                  $$   $$   $$$\n"
                 "                 $$        $$$\n"
                 "                  $$$    $$$\n"
                 "                     $$$$\n";
    std::cout << "\n                    GEEK_ON\n\n\n"
                 "                   Click ENTER\n";
    std::cin.get();
}

Uint32 styleParameter() {
    return Style::Titlebar+Style::Close;
}

void initializationGObjects(RenderWindow &window, std::vector<std::pair<CircleShape, int>> &circles, std::vector<std::pair<RectangleShape, int>> &rectangles) {
    window.setPosition(sf::Vector2<int>(400, 220));

    double radius = 25.f;
    double thickness = 10.f;
    int x = 0, y = 35, m = static_cast<int>(window.getSize().x/circles.size() - 2*(radius+thickness))/2;

    for (std::pair<CircleShape, int> &circle : circles) {
        x += m;
        circle.first.setRadius(radius);
        circle.first.setOutlineThickness(thickness);
        circle.first.setOutlineColor(sf::Color(130, 51, 51));
        circle.first.move(x, y);

        x += m + 2*(radius+thickness);
    }

    double weight = 2*(radius+thickness);
    double height = 40.f;
    x = 0;
    y = 220;
    m = static_cast<int>(window.getSize().x/rectangles.size() - weight)/2;

    for (std::pair<RectangleShape,int> &rectangle : rectangles) {
        x += m;
        rectangle.first.setSize(sf::Vector2f(weight,height));
        rectangle.first.setFillColor(sf::Color(71, 71, 204));
        rectangle.first.setOutlineThickness(7);
        rectangle.first.setOutlineColor(sf::Color(0,0,0,0));
        rectangle.first.move(x, y);
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

void action(std::vector<std::pair<CircleShape, int>> &circles, short index) {
    if (index != -1) {
        for (std::pair<CircleShape, int> &circle: circles) {
            if (circle.second == index) {
                circle.first.setFillColor(Color(239, 169, 31));
                break;
            }
        }
    }
}

void processEvent(RenderWindow &window, std::vector<std::pair<CircleShape, int>> &circles, std::vector<std::pair<sf::RectangleShape, int>> &rectangles, Lab3C::printedCircuitBoard &_arduino) {
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
            for (std::pair<RectangleShape, int> &rectangle : rectangles) {
                if (pointBelongToRectangle(positionOfMouse, rectangle.first)) {
                    rectangle.first.setOutlineColor(sf::Color(255, 54, 101, 100));
                    action(circles, _arduino[rectangle.second].numberOfContact);
                    break;
                }
            }
        } else {
            for (std::pair<RectangleShape, int> &rectangle : rectangles)
                rectangle.first.setOutlineColor(sf::Color(0,0,0, 0));
            for (std::pair<CircleShape, int> &circle : circles)
                circle.first.setFillColor(Color(255, 255, 255));
        }
    }
    // Установка цвета фона
    window.clear(Color(181, 181, 181, 0));

    // Закрашиваем наш круг
    for (std::pair<CircleShape, int> &circle : circles) {
        //circle.first.setFillColor(Color(239, 169, 31));
        window.draw(circle.first);
    }

    for (std::pair<sf::RectangleShape, int> &rectangle : rectangles) {
        window.draw(rectangle.first);
    }

    // Отрисовка окна
    window.display();
}

namespace sf {

}
