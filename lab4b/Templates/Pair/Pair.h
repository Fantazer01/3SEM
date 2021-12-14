//
// Created by oleg on 13.12.2021.
//

#ifndef TEMPLATES_PAIR_H
#define TEMPLATES_PAIR_H

template <typename T>
void Swap(T &temp1, T &temp2)
{
    T temp3 = temp1;
    temp1 = temp2;
    temp2 = temp3;
}

template <typename T1, typename T2>
struct Pair {
public:
    T1 first;
    T2 second;

    Pair() = default;
    Pair(const T1 &temp1, const T2 &temp2): first(temp1), second(temp2) {}

    bool operator == (const Pair<T1, T2> &_pair_) const
    { return (first == _pair_.first && second == _pair_.second); }
    bool operator != (const Pair<T1, T2> &_pair_) const { return !((*this) == _pair_);}
};

template <typename T1, typename T2>
Pair<T1, T2> Make_pair(T1 temp1, T2 temp2)
{
    return Pair<T1, T2>( temp1, temp2);
}

#endif //TEMPLATES_PAIR_H
