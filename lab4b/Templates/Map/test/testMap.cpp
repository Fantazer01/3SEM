//
// Created by oleg on 13.12.2021.
//

#include "gtest/gtest.h"
#include "Map.h"


TEST(Map, Insert)
{
    Map ABC;

    ASSERT_EQ(0, ABC.size());
    ASSERT_EQ(true, ABC.empty());

    ASSERT_EQ(true, ABC.insert(Make_pair(Key(1), Info(1))));
    ASSERT_EQ(1, ABC.size());
    ASSERT_EQ(false, ABC.empty());

    ASSERT_EQ(false, ABC.insert(Make_pair(Key(1), Info(1))));
    ASSERT_EQ(1, ABC.size());

    ASSERT_EQ(false, ABC.insert(Make_pair(Key(1), Info(123))));
    ASSERT_EQ(1, ABC.size());

}

TEST(Map, Find)
{
    Map ABC;

    ABC.insert(Make_pair(Key(1), Info(1)));
    ABC.insert(Make_pair(Key(2), Info(2)));
    ABC.insert(Make_pair(Key(3), Info(3)));
    ABC.insert(Make_pair(Key(4), Info(4)));
    ABC.insert(Make_pair(Key(-4), Info(-4)));

    ASSERT_EQ(Make_pair(Key(1), Info(1)), *(ABC.find(Key(1))));
    ASSERT_EQ(Make_pair(Key(2), Info(2)), *(ABC.find(Key(2))));
    ASSERT_EQ(Make_pair(Key(3), Info(3)), *(ABC.find(Key(3))));
    ASSERT_EQ(Make_pair(Key(4), Info(4)), *(ABC.find(Key(4))));
    ASSERT_EQ(Make_pair(Key(-4), Info(-4)), *(ABC.find(Key(-4))));

    ASSERT_EQ(ABC.end(), ABC.find(Key(999)));
}

TEST(Map, Erase)
{
    Map ABC;

    ABC.insert(Make_pair(Key(1), Info(1)));
    ABC.insert(Make_pair(Key(2), Info(2)));
    ABC.insert(Make_pair(Key(3), Info(3)));
    ABC.insert(Make_pair(Key(4), Info(4)));
    ABC.insert(Make_pair(Key(-4), Info(-4)));

    ASSERT_EQ(5, ABC.size());

    ASSERT_EQ(Make_pair(Key(1), Info(1)), *(ABC.find(Key(1))));
    ASSERT_EQ(true, ABC.erase(Key(1)));
    ASSERT_EQ(ABC.end(), ABC.find(Key(1)));
    ASSERT_EQ(4, ABC.size());

    ASSERT_EQ(Make_pair(Key(-4), Info(-4)), *(ABC.find(Key(-4))));
    ASSERT_EQ(true, ABC.erase(Key(-4)));
    ASSERT_EQ(ABC.end(), ABC.find(Key(-4)));
    ASSERT_EQ(3, ABC.size());

    ASSERT_EQ(Make_pair(Key(2), Info(2)), *(ABC.find(Key(2))));
    ASSERT_EQ(true, ABC.erase(Key(2)));
    ASSERT_EQ(ABC.end(), ABC.find(Key(2)));
    ASSERT_EQ(2, ABC.size());

    ASSERT_EQ(Make_pair(Key(3), Info(3)), *(ABC.find(Key(3))));
    ASSERT_EQ(true, ABC.erase(Key(3)));
    ASSERT_EQ(ABC.end(), ABC.find(Key(3)));
    ASSERT_EQ(1, ABC.size());

    ASSERT_EQ(Make_pair(Key(4), Info(4)), *(ABC.find(Key(4))));
    ASSERT_EQ(true, ABC.erase(Key(4)));
    ASSERT_EQ(ABC.end(), ABC.find(Key(4)));
    ASSERT_EQ(0, ABC.size());

}



int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}