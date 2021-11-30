//
// Created by oleg on 11.11.2021.
//

#include "gtest/gtest.h"
#include "Person.h"

using namespace lab4;

TEST(Person, DefaulConstructor)
{
    FullName name;
    ASSERT_EQ("", name.First_name);
    ASSERT_EQ("", name.Last_name);
    ASSERT_EQ("", name.Patronymic);

    Person smbd;

    ASSERT_EQ(name, smbd.getName());
    ASSERT_EQ("", smbd.getRank());
    ASSERT_EQ(0, smbd.getStanding());
}

TEST(Person, mainConstructor)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd("boss", name, 5);

    ASSERT_EQ(name, smbd.getName());
    ASSERT_EQ("boss", smbd.getRank());
    ASSERT_EQ(5, smbd.getStanding());
}

TEST(Person, Modificate)
{
    FullName name = { "Simpson", "Tom", "Ivanovich"};
    Person smbd;

    smbd.setName(name);
    ASSERT_EQ(name, smbd.getName());
    smbd.setRank("boss");
    ASSERT_EQ("boss", smbd.getRank());
    smbd.setStanding(5);
    ASSERT_EQ(5, smbd.getStanding());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

