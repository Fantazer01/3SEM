#include "gtest/gtest.h"
#include "LineCassini.h"
#include <vector>
#include <iostream>

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
    LineCassini line(5, 5);
    //distFromOrigin
    std::vector <double> v = line.distFromOrigin(0);
    ASSERT_EQ(2, )
    ASSERT_NEAR(7.07, v[0], 0.005);
    ASSERT_NEAR(0, v[1], 0.005);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
