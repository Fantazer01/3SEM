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

        bool operator == (const FullName &name) const
        { return (First_name == name.First_name && Last_name == name.Last_name && Patronymic == name.Patronymic); }

        friend std::ostream& operator << (std::ostream&, const FullName &name);
    };

    class Person {
    private:
        std::string rank;
        FullName name;
        uint standing;
    public:
        Person() : standing(0) {}

        Person(std::string _rank, FullName _name, uint _stand)
        : rank(std::move(_rank)), name(std::move(_name)), standing(_stand) {}

        std::string getRank() const { return rank; }

        FullName getName() const { return name; }

        unsigned int getStanding() const { return standing; }

        void setRank(std::string _rank) { rank = std::move(_rank); }

        void setName(FullName _name) { name = std::move(_name); }

        void setStanding(unsigned int _standing) { standing = _standing; }

        bool operator == (const Person &person) const
        { return (rank == person.rank && name == person.name && standing == person.standing); }

        friend std::ostream& operator << (std::ostream&, const Person &person);

    };

}

#endif //LAB4_PERSON_H
