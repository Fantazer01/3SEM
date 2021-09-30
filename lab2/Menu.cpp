//
// Created by oleg on 29.09.2021.
//
#include <iostream>
#include "../LabTools/LabTools.h"
#include "Menu.h"

int dialog(const char **msgs, int NMsgs) {
    int i, a = 0;
    for (i = 0; i < NMsgs; ++i)
        std::cout << i << ". " << msgs[i] << std::endl;

    do {
        try {
            getNum(a);
        } catch (const char* str) {
            std::cout << "EOF" << std::endl;
            return 0;
        }
    } while (a < 0 || a >= NMsgs);
    system("clear");
    return a;
}

int getA(LineCassini &line) {
    std::cout << "Parametr A: " << line.getA() << std::endl;
    return 1;
}

int getC(LineCassini &line) {
    std::cout << "Parametr C: " << line.getC() << std::endl;
    return 1;
}

int distFromOrigin(LineCassini &line) {
    int i;
    double d = 0;
    std:: cin >> d;
    std::vector <double> v = line.distFromOrigin(d);
    if (v.empty())
        std::cout << "There are no points.";
    else {
        std::cout << "Distance to found points" << std::endl;
        for (i = 0; i < v.size(); ++i)
            std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 1;
}

int setA(LineCassini &line) {
    std::cout << "Enter number, parametr a:" << std::endl;
    double d = 0;
    std::cin >> d;
    if (d >= 0) {
        line.setA(d);
        std::cout << "Ready" << std::endl;
    } else
        std::cout << "Sorry, but numbers must be positive" << std::endl;
    return 1;
}

int setC(LineCassini &line) {
    std::cout << "Enter number, parametr c:" << std::endl;
    double d = 0;
    std::cin >> d;
    if (d >= 0) {
        line.setC(d);
        std::cout << "Ready" << std::endl;
    } else
        std::cout << "Sorry, but numbers must be positive" << std::endl;
    return 1;
}

int setAC(LineCassini &line) {
    std::cout << "Enter two numbers, parametr a and parametr c:" << std::endl;
    double d1 = 0, d2 = 0;
    std::cin >> d1 >> d2;
    if (d1 >= 0 && d2 >= 0) {
        line.setAC(d1, d2);
        std::cout << "Ready" << std::endl;
    } else
        std::cout << "Sorry, but numbers must be positive" << std::endl;
    return 1;
}

int formLine(LineCassini &line) {
    char *s = line.formLineCassini();

    std::cout << "Now our object is " << s << std::endl;
    return 1;
}

int radiusOfCurvature(LineCassini &line) {
    int i;
    std::cout << "Enter number, angle:" << std::endl;
    double d = 0;
    std::cin >> d;
    std::vector <double> v = line.radiusOfCurvature(d);
    if (v.empty())
        std::cout << "There are no points.";
    else {
        std::cout << "Radius to found points" << std::endl;
        for (i = 0; i < v.size(); ++i)
            std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 1;
}

int inflectionPointCoordinates(LineCassini &line) {
    int i;
    std::vector <Point> v = line.inflectionPointCoordinates();
    if (v.empty())
        std::cout << "Line doesn't have inflection point" << std::endl;
    else {
        std::cout << "Inflection points:" << std::endl;
        for (i = 0; i < v.size(); ++i)
            std::cout << i << ". " << v[i].x << " " << v[i].y << std::endl;
    }
    return 1;
}

int equationOfLine(LineCassini &line) {
    char *s = line.equationOfLine();
    std::cout << s << std::endl;
    delete [] s;
    return 1;
}

