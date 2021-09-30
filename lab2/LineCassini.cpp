//
// Created by oleg on 29.09.2021.
//

#include "LineCassini.h"
#include <cmath>
#include <vector>
#include <cstdio>



std::vector <double> LineCassini::distFromOrigin(double angle) const {
    double p = 0, b;
    std::vector <double> v;
    b = pow(a, 4)-pow(c, 4)*pow(sin(2*angle), 2);
    if (b >= 0) {
        p = c*c*cos(2*angle)+sqrt(b);
        v.push_back(sqrt(p));
        p = c*c*cos(2*angle)-sqrt(b);
        if (p >= 0)
            v.push_back((sqrt(p)));
    }
    return v;
}

int LineCassini::formLine() const {
    if (a < c)
        return 0;
    else if (a == c)
        return 1;
    else if (a < c*sqrt(2))
        return 2;
    return 3;
}

char* LineCassini::formLineCassini() const {
    char *s[] = {"two oval", "lemniscate Bernoulli", "concave oval", "oval"};
    int type = (*this).formLine();
    return s[type];
}

std::vector <double> LineCassini::radiusOfCurvature(double angle) const {
    std::vector <double> v = (*this).distFromOrigin(angle), v2;
    for (int i; i < v.size(); ++i)
        v2.push_back(pow(a, 2) * v[i]/(pow(v[i], 2) + pow(c, 2)*cos(2*angle)));
    return v;
}

std::vector <Point> LineCassini::inflectionPointCoordinates() const {
    struct Point point{0,0};
    double p, fi;
    std::vector <Point> v;
    int n = (*this).formLine();
    if (n != 2)
        return v;
    p = (pow(a, 4) - pow(c, 4)) / 3;
    p = sqrt(sqrt(p));
    fi = acos(-sqrt((pow(a/c, 4) - 1)/3)) / 2;

    point.x = -p*cos(-fi);
    point.y = p*sin(-fi);
    v.push_back(point);
    point.x = -p*cos(fi);
    point.y = p*sin(fi);
    v.push_back(point);
    point.x = p*cos(-fi);
    point.y = p*sin(-fi);
    v.push_back(point);
    point.x = p*cos(fi);
    point.y = p*sin(fi);
    v.push_back(point);

    return v;
}

char* LineCassini::equationOfLine() const {
    char *s = new char[80];
    s[0] = '\0';
    if (c == 0)
        sprintf(s, "(x^2+y^2)^2=%0.2f^4", a);
    else
        sprintf(s, "(x^2+y^2)^2+2%0.2f^2*(x^2-y^2)=%0.2f^4-%0.2f^4", c, a, c);
    return s;
}

LineCassini& LineCassini::setA(double a) {
    if (a < 0)
        throw -1;
    LineCassini::a = a;
    return *this;
}

LineCassini& LineCassini::setC(double c) {
    if (c < 0)
        throw -1;
    LineCassini::c = c;
    return *this;
}

LineCassini& LineCassini::setAC(double a, double c) {
    (*this).setA(a);
    (*this).setC(c);
    return *this;
}
