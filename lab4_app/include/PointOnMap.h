//
// Created by oleg on 08.01.2022.
//

#ifndef LAB4_APP_POINTONMAP_H
#define LAB4_APP_POINTONMAP_H

#include <string>
#include <utility>

class PointOnMap {
private:
    std::string name;
    double x;
    double y;
public:
    PointOnMap(): x(0.0), y(0.0) {}
    PointOnMap(std::string _name, double _x, double _y): name(std::move(_name)), x(_x), y(_y) {}

    std::string getName() const { return name; }
    double get1stCoordinate() const { return x; }
    double get2ndCoordinate() const { return y; }

    void setName(std::string _name) { name = std::move(_name); }
    void set1stCoordinate(double temp) { x = temp; }
    void set2ndCoordinate(double temp) { y = temp; }

    double getDistance(PointOnMap point) const;
};


#endif //LAB4_APP_POINTONMAP_H
