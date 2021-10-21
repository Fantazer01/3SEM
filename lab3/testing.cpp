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

TEST(StackTest, OperatorPlus) {
    lab3::Data data[3];
    data[0].a = 1;
    data[1].a = 2;
    data[2].a = 3;

    lab3::Stack stack1, stack2;
    stack1.push(data[0]).push(data[1]);
    stack2.push(data[2]);

    lab3::Stack stack3 = stack1 + stack2;

    ASSERT_EQ(3, stack3.pop().a);
    ASSERT_EQ(2, stack3.pop().a);
    ASSERT_EQ(1, stack3.pop().a);
}

TEST(StackTest, OperatorINV) {
    lab3::Data data[3];
    data[0].a = 1;
    data[1].a = 2;
    data[2].a = 3;

    lab3::Stack stack1(3, data);

    lab3::Stack stack2 = ~stack1;

    ASSERT_EQ(1, stack2.pop().a);
    ASSERT_EQ(2, stack2.pop().a);
    ASSERT_EQ(3, stack2.pop().a);
}

TEST(StackTest, OperatorPlusEqual) {
    lab3::Data data[3];
    data[0].a = 1;
    data[1].a = 2;
    data[2].a = 3;

    lab3::Stack stack1, stack2;
    stack1.push(data[0]).push(data[1]);
    stack2.push(data[2]);

    stack1 += stack2;

    ASSERT_EQ(3, stack1.pop().a);
    ASSERT_EQ(2, stack1.pop().a);
    ASSERT_EQ(1, stack1.pop().a);
}

TEST(StackTest, OperatorIndex) {
    lab3::Data data[3];
    data[0].a = 1;
    data[1].a = 2;
    data[2].a = 3;

    lab3::Stack stack1(3, data);

    ASSERT_EQ(3, stack1[2].a);
    ASSERT_EQ(2, stack1[1].a);
    ASSERT_EQ(1, stack1[0].a);

}

TEST(StackTest, OperatorMinusMinus) {
    lab3::Data data[3];
    data[0].a = 1;
    data[1].a = 2;
    data[2].a = 3;

    lab3::Stack stack1(3, data);
    ASSERT_EQ(3, stack1.size());
    --stack1;
    ASSERT_EQ(2, stack1.size());
    ASSERT_EQ(2, stack1[1].a);
    ASSERT_EQ(1, stack1[0].a);

    ASSERT_EQ(2, stack1.size());
    stack1--;
    ASSERT_EQ(1, stack1.size());
    ASSERT_EQ(1, stack1.pop().a);

}

TEST(StackTest, OperatorBrackets) {
    lab3::Data data(1, "a1");

    lab3::Stack stack1;

    stack1(data);

    ASSERT_EQ(1, stack1.pop().a);

}

TEST(StackTest, Operator1) {
    const lab3::Stack stack;
}




int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

