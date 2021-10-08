#include "gtest/gtest.h"
#include "LineCassini.h"
#include <vector>
#include <iostream>
#include <cmath>

TEST(LineCassiniTest, DefaultConstructor)
{
    LineCassini line;
    ASSERT_EQ(0, line.getA());
    ASSERT_EQ(0, line.getC());
}

TEST(LineCassiniTest, InitConstructor)
{
    LineCassini line(5, 5);
    ASSERT_EQ(5, line.getA());
    ASSERT_EQ(5, line.getC());

    LineCassini line2(10);
    ASSERT_EQ(10, line2.getA());
    ASSERT_EQ(0, line2.getC());
}

TEST(LineCassiniTest, TestException)
{
    ASSERT_ANY_THROW(LineCassini(-5));
    ASSERT_ANY_THROW(LineCassini(3, -1.005));
    ASSERT_ANY_THROW(LineCassini(-1.005, 3));
    ASSERT_ANY_THROW(LineCassini(-3, -1.005));
}

TEST(LineCassiniTest, Setters)
{
    LineCassini line;
    //modification
    ASSERT_EQ(3.3, line.setA(3.3).getA());
    ASSERT_EQ(3.456, line.setC(3.456).getC());
    //throw
    ASSERT_ANY_THROW(line.setA(-0.23));
    ASSERT_ANY_THROW(line.setC(-0.23));
}

TEST(LineCassiniTest, Selectors)
{
    double angle = 0, a, c;
    //лемниската Бернули
    LineCassini line(5, 5);
    a = line.getA();
    c = line.getC();

    //distFromOrigin
    //получаем две точки, одна на дуге, другая в центре лемнискаты
    std::vector <double> v = line.distFromOrigin(angle);
    ASSERT_EQ(2, v.size());
    ASSERT_NEAR(sqrt(pow(c, 2)*cos(2*angle)+sqrt(pow(a, 4)-pow(c, 4)*pow(sin(2*angle), 2))), v[0], 0.005);
    ASSERT_NEAR(sqrt(c*c*cos(2*angle)-sqrt(pow(a, 4)-pow(c, 4)*pow(sin(2*angle), 2))), v[1], 0.005);
    //меняем угол
    angle = 0.5;
    v = line.distFromOrigin(angle);
    ASSERT_EQ(2, v.size());
    ASSERT_NEAR(sqrt(c*c*cos(2*angle)+sqrt(pow(a, 4)-pow(c, 4)*pow(sin(2*angle), 2))), v[0], 0.005);
    ASSERT_NEAR(0, v[1], 0.005);
    //меняем угол, получаем лишь одну точку - в центре лемнискаты
    angle = 0.9;
    v = line.distFromOrigin(angle);
    ASSERT_EQ(1, v.size());
    ASSERT_NEAR(0, v[1], 0.005);
    //форма два овала, ни одной точки луч не пересекает
    line.setAC(4.4, 5);
    angle = 0.9;
    v = line.distFromOrigin(angle);
    ASSERT_EQ(0, v.size());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
