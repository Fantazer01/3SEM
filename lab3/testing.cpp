//
// Created by oleg on 13.10.2021.
//

#include "gtest/gtest.h"
#include "Stack.h"
#include <vector>
#include <iostream>
#include <cmath>

TEST(StackTest, MainMethods) {
    lab3::Data data{1, "abc"};
    Lab3::Data data2{};
    lab3::Stack stack;
    ASSERT_EQ(0, stack.size());
    ASSERT_EQ(1, stack.push(data).size());
    data2 = stack.pop();
    ASSERT_EQ(1, data2.a);
    ASSERT_STREQ("abc", data.s);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

