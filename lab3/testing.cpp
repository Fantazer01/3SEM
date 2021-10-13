//
// Created by oleg on 13.10.2021.
//

#include "gtest/gtest.h"
#include "Stack.h"
#include <iostream>
#include <cstring>

TEST(StackTest, MainMethods) {
    lab3::Data data(1, "abc");
    lab3::Data data2;
    lab3::Stack stack;
    ASSERT_EQ(0, stack.size());
    ASSERT_EQ(1, stack.push(data).size());
    data2 = stack.pop();
    ASSERT_EQ(1, data2.a);
    ASSERT_STREQ("abc", data.s);
}

TEST(StackTest, constructorArray) {
    lab3::Data data[3];
    data[0].a = 1;
    strcpy(data[0].s, "11");
    data[1].a = 2;
    strcpy(data[1].s, "22");
    data[2].a = 3;
    strcpy(data[2].s, "33");

    lab3::Stack stack(3, data);
    ASSERT_EQ(3, stack.size());
    lab3::Data data2 = stack.pop();
    ASSERT_EQ(3, data2.a);
    ASSERT_STREQ("33", data2.s);
    data2 = stack.pop();
    ASSERT_EQ(2, data2.a);
    ASSERT_STREQ("22", data2.s);
    data2 = stack.pop();
    ASSERT_EQ(1, data2.a);
    ASSERT_STREQ("11", data2.s);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

