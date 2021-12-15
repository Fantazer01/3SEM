//
// Created by oleg on 13.12.2021.
//

#include "gtest/gtest.h"
#include "Map.h"

class Key {
private:
    int a;
public:
    Key() = default;
    explicit Key(int _a): a(_a) {}

    int getA() const { return a; }
    void setA(int _a) { a = _a; }

    bool operator ==(const Key &temp) const { return a == temp.a; }
    bool operator !=(const Key &temp) const { return a != temp.a; }
    bool operator < (const Key &temp) const { return a < temp.a; }
    bool operator <= (const Key &temp) const { return a <= temp.a; }
    bool operator > (const Key &temp) const { return a > temp.a; }
    bool operator >= (const Key &temp) const { return a >= temp.a; }

};

class Info {
private:
    int a;
public:
    Info() = default;
    explicit Info(int _a): a(_a) {}

    int getA() const { return a; }
    void setA(int _a) { a = _a; }

    bool operator ==(const Info &temp) const { return a == temp.a; }
    bool operator !=(const Info &temp) const { return a != temp.a; }
    bool operator < (const Info &temp) const { return a < temp.a; }
    bool operator <= (const Info &temp) const { return a <= temp.a; }
    bool operator > (const Info &temp) const { return a > temp.a; }
    bool operator >= (const Info &temp) const { return a >= temp.a; }

};


TEST(Map, Insert)
{
    Map<Key, Info> ABC;

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
    Map<Key, Info> ABC;

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
    Map<Key, Info> ABC;

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

TEST(Map, IteratorPlusPlusCase0_EmptyMap)
{
    Map<Key, Info> ABC;

    int i;
    Map<Key, Info>::iterator it;
    for (i = 1, it = ABC.begin(); it != ABC.end(); ++i, ++it)
        ;
    ASSERT_EQ(1, i);

}

TEST(Map, IteratorPlusPlusCase1_FullTree)
{
    Map<Key, Info> ABC;

    //1 level
    ABC.insert(Make_pair(Key(4), Info(4)));
    //2 level
    ABC.insert(Make_pair(Key(2), Info(2)));
    ABC.insert(Make_pair(Key(6), Info(6)));
    //3 level
    ABC.insert(Make_pair(Key(1), Info(1)));
    ABC.insert(Make_pair(Key(3), Info(3)));
    ABC.insert(Make_pair(Key(5), Info(5)));
    ABC.insert(Make_pair(Key(7), Info(7)));
    /*
     *          _4_
     *      _2_     _6_
     *    _1_ _3_ _5_ _7_
     */

    int i;
    Map<Key, Info>::iterator it;
    for (i = 1, it = ABC.begin(); it != ABC.end(); ++i, ++it)
        ASSERT_EQ(Make_pair(Key(i), Info(i)), *it);

}

TEST(Map, IteratorPlusPlusCase2_NoFullTree)
{
    Map<Key, Info> ABC;

    //1 level
    ABC.insert(Make_pair(Key(3), Info(3)));
    //2 level
    ABC.insert(Make_pair(Key(2), Info(2)));
    ABC.insert(Make_pair(Key(5), Info(5)));
    //3 level
    ABC.insert(Make_pair(Key(1), Info(1)));
    ABC.insert(Make_pair(Key(4), Info(4)));
    /*
     *          _3_
     *      _2_     _5_
     *    _1_     _4_
     */

    int i;
    Map<Key, Info>::iterator it;
    for (i = 1, it = ABC.begin(); it != ABC.end(); ++i, ++it)
        ASSERT_EQ(Make_pair(Key(i), Info(i)), *it);

}

TEST(Map, IteratorPlusPlusCase3_LeftLine)
{
    Map<Key, Info> ABC;

    //1 level
    ABC.insert(Make_pair(Key(3), Info(3)));
    //2 level
    ABC.insert(Make_pair(Key(2), Info(2)));
    //3 level
    ABC.insert(Make_pair(Key(1), Info(1)));
    /*
     *         _3_
     *      _2_
     *    _1_
     */

    int i;
    Map<Key, Info>::iterator it;
    for (i = 1, it = ABC.begin(); it != ABC.end(); ++i, ++it)
        ASSERT_EQ(Make_pair(Key(i), Info(i)), *it);

}

TEST(Map, IteratorPlusPlusCase4_RightLine)
{
    Map<Key, Info> ABC;

    //1 level
    ABC.insert(Make_pair(Key(1), Info(1)));
    //2 level
    ABC.insert(Make_pair(Key(2), Info(2)));
    //3 level
    ABC.insert(Make_pair(Key(3), Info(3)));
    /*
     *          _1_
     *             _2_
     *                _3_
     */

    int i;
    Map<Key, Info>::iterator it;
    for (i = 1, it = ABC.begin(); it != ABC.end(); ++i, ++it)
        ASSERT_EQ(Make_pair(Key(i), Info(i)), *it);

}

TEST(Map, IteratorPlusPlusCase5_LeftSubtree)
{
    Map<Key, Info> ABC;

    //1 level
    ABC.insert(Make_pair(Key(4), Info(4)));
    //2 level
    ABC.insert(Make_pair(Key(2), Info(2)));
    //3 level
    ABC.insert(Make_pair(Key(1), Info(1)));
    ABC.insert(Make_pair(Key(3), Info(3)));
    /*
     *          _4_
     *      _2_
     *    _1_ _3_
     */

    int i;
    Map<Key, Info>::iterator it;
    for (i = 1, it = ABC.begin(); it != ABC.end(); ++i, ++it)
        ASSERT_EQ(Make_pair(Key(i), Info(i)), *it);

}

TEST(Map, IteratorPlusPlusCase1_RightSubtree)
{
    Map<Key, Info> ABC;

    //1 level
    ABC.insert(Make_pair(Key(1), Info(1)));
    //2 level
    ABC.insert(Make_pair(Key(3), Info(3)));
    //3 level
    ABC.insert(Make_pair(Key(2), Info(2)));
    ABC.insert(Make_pair(Key(4), Info(4)));
    /*
     *          _1_
     *              _3_
     *            _2_ _4_
     */

    int i;
    Map<Key, Info>::iterator it;
    for (i = 1, it = ABC.begin(); it != ABC.end(); ++i, ++it)
        ASSERT_EQ(Make_pair(Key(i), Info(i)), *it);

}



int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}