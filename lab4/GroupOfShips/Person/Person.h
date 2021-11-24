//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_PERSON_H
#define LAB4_PERSON_H

#include <string>
#include <utility>

namespace lab4 {

    struct FullName {
        std::string First_name;
        std::string Last_name;
        std::string Patronymic;

        friend std::ostream& operator << (std::ostream&, const FullName &name);
    };

    class Person {
    private:
        std::string rank;
        FullName name;
        unsigned int standing;
    public:
        Person() : standing(0) {}

        Person(const std::string &_rank, const FullName &_name, unsigned int _stand) : rank(_rank), name(_name), standing(_stand) {}

        std::string getRank() const { return rank; }

        FullName getName() const { return name; }

        unsigned int getStanding() const { return standing; }

        void setRank(std::string _rank) { rank = std::move(_rank); }

        void setName(FullName _name) { name = std::move(_name); }

        void setStanding(unsigned int _standing) { standing = _standing; }

        friend std::ostream& operator << (std::ostream&, const Person &person);

    };

}

#endif //LAB4_PERSON_H
