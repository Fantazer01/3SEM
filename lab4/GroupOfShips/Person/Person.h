//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_PERSON_H
#define LAB4_PERSON_H

#include <string>

namespace lab4 {

    struct FullName {
        std::string First_name;
        std::string Last_name;
        std::string Patronymic;
    };

    class Person {
    private:
        std::string rank;
        FullName name;
        int standing;
    public:
        Person() : standing(0) {}

        Person(std::string _rank, FullName _name, int _stand) : rank(_rank), name(_name), standing(_stand) {}

        std::string getRank() { return rank; }

        FullName getName() { return name; }

        int getStanding() { return standing; }

        void setRank(std::string _rank) { rank = _rank; }

        void setName(FullName _name) { name = _name; }

        void setStanding(int _standing);

    };

}

#endif //LAB4_PERSON_H
