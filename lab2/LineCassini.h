//
// Created by oleg on 29.09.2021.
//

#include <vector>
#include "gtest/gtest.h"

#ifndef LAB2_LINECASSINI_H
#define LAB2_LINECASSINI_H

struct Point {
    double x;
    double y;
};


class LineCassini {
private:
    double a;
    double c;
    [[nodiscard]] int formLine() const;
public:
    //constructors
    LineCassini():a(0), c(0) {}
    LineCassini(double a, double c = 0) {
        if (c < 0 || a < 0)
            throw -1;
        LineCassini::a = a;
        LineCassini::c = c;
    }
    //selectors
    [[nodiscard]] double getA() const {return a;}
    [[nodiscard]] double getC() const {return c;}
    [[nodiscard]] std::vector <double>  distFromOrigin(double angle) const;
    [[nodiscard]] char* formLineCassini() const;
    [[nodiscard]] std::vector <double> radiusOfCurvature(double angle) const;
    [[nodiscard]] std::vector <Point> inflectionPointCoordinates() const;
    [[nodiscard]] char* equationOfLine() const;
    //modifiers
    LineCassini& setA(double a);
    LineCassini& setC(double c);
    LineCassini& setAC(double a, double c);

};


#endif //LAB2_LINECASSINI_H
