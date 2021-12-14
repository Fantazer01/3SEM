//
// Created by oleg on 13.12.2021.
//

#include "gtest/gtest.h"
#include "Pair.h"

#include <utility>

class Test_class {
private:
    int temp1;
    std::string temp2;
public:
    Test_class(): temp1(0), temp2() {}
    Test_class(int _temp1, std::string _temp2): temp1(_temp1), temp2(std::move(_temp2)) {}

    int getTemp1() const { return temp1; }
    std::string getTemp2() const { return temp2; }

};


TEST(Pair, Constructor)
{
    Pair<int, int> some_pair(1, 2);

    ASSERT_EQ(1, some_pair.first);
    ASSERT_EQ(2, some_pair.second);

    Pair<int, double> some_pair2(3, 2.123);

    ASSERT_EQ(3, some_pair2.first);
    ASSERT_EQ(2.123, some_pair2.second);

    Pair<Test_class, int> some_pair3(Test_class(1, "abc"), 5);

    ASSERT_EQ(1, some_pair3.first.getTemp1());
    ASSERT_EQ("abc", some_pair3.first.getTemp2());
    ASSERT_EQ(5, some_pair3.second);
}

TEST(Pair, Equal)
{
    Pair<int, int> some_pair1(1, 2), some_pair2(1, 2), some_pair3(3, 4);

    ASSERT_EQ(true, some_pair1 == some_pair2);
    ASSERT_EQ(false, some_pair1 != some_pair2);

    ASSERT_EQ(false, some_pair1 == some_pair3);
    ASSERT_EQ(true, some_pair1 != some_pair3);
}

TEST(Pair_func, Make_pair)
{
    Pair<int, int> some_pair(1, 2);

    ASSERT_EQ(true, some_pair == Make_pair(1, 2));

    Pair<std::string, int> some_pair2("ABC", 2);

    ASSERT_EQ(true, some_pair2 == Make_pair(std::string("ABC"), 2));

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}