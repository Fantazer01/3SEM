//
// Created by oleg on 29.09.2021.
//

#ifndef LAB2_LINECASSINI_H
#define LAB2_LINECASSINI_H


class LineCassini {
private:
    double a;
    double c;
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
    double getA() const {return a;}
    double getC() const {return c;}
    double distFromOrigin(double angle);
    //modifiers
    LineCassini& setA(double a);
    LineCassini& setC(double c);
    LineCassini& setAC(double a, double c);
};


#endif //LAB2_LINECASSINI_H
