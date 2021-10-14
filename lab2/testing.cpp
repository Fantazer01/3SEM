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

TEST(LineCassiniTest, Selectors_distFromOrigin)
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

TEST(LineCassiniTest, Selectors_formLineCassini)
{
    LineCassini line(5, 5);
    ASSERT_STREQ("lemniscate Bernoulli", line.formLineCassini());
    line.setAC(4.4, 5);
    ASSERT_STREQ("two oval", line.formLineCassini());
    line.setAC(5, 4.7);
    ASSERT_STREQ("concave oval", line.formLineCassini());
    line.setAC(5, 3);
    ASSERT_STREQ("oval", line.formLineCassini());
}

TEST(LineCassiniTest, Selectors_radiusOfCurvature)
{
    double angle = 0;
    LineCassini line(4.4, 5);
    std::vector <double> v = line.distFromOrigin(angle), v2;
    v2 = line.radiusOfCurvature(angle);

    ASSERT_EQ(2, v2.size());
    ASSERT_NEAR(pow(line.getA(), 2) * v[0]/(pow(v[0], 2) + pow(line.getC(), 2)*cos(2*angle)), v2[0], 0.005);
    ASSERT_NEAR(pow(line.getA(), 2) * v[1]/(pow(v[1], 2) + pow(line.getC(), 2)*cos(2*angle)), v2[1], 0.005);

}

TEST(LineCassiniTest, Selectors_inflectionPointCoordinates)
{
    LineCassini line(5, 5);
    std::vector <Point> v = line.inflectionPointCoordinates();
    ASSERT_EQ(0, v.size());
    v.clear();

    line.setAC(4.4, 5);
    v = line.inflectionPointCoordinates();
    ASSERT_EQ(0, v.size());
    v.clear();

    line.setAC(5, 4.7);
    v = line.inflectionPointCoordinates();
    ASSERT_EQ(4, v.size());

    v.clear();

    line.setAC(5, 3);
    v = line.inflectionPointCoordinates();
    ASSERT_EQ(0, v.size());
    v.clear();
}

TEST(LineCassiniTest, Selectors_equationOfLine)
{
    LineCassini line(5, 5);
    char s[100], *ans;
    if (line.getC() == 0)
        sprintf(s, "(x^2+y^2)^2=%0.2f", pow(line.getA(), 4));
    else
        sprintf(s, "(x^2+y^2)^2+%0.2f*(x^2-y^2)=%0.2f", 2*pow(line.getC(),2), pow(line.getA(), 4)-pow(line.getC(), 4));
    ASSERT_STREQ(s, ans=line.equationOfLine());
    delete[] ans;
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
