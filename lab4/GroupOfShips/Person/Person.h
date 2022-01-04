//
// Created by oleg on 10.11.2021.
//

/*!
 * @file
 * @brief description for class Person
 *
 * stores struct FullName and class Person
 * stores information about a person's name, rank and experience
 */

#ifndef LAB4_PERSON_H
#define LAB4_PERSON_H

#include <string>
#include <utility>

namespace lab4 {

    /*!
     * @brief struct description person's name
     */
    struct FullName {
        std::string First_name;
        std::string Last_name;
        std::string Patronymic;

        /*!
         * Compare two struct FullName
         * @param[in] name name another person for comparing
         * @return names is equal or not
         */
        bool operator == (const FullName &name) const
        { return (First_name == name.First_name && Last_name == name.Last_name && Patronymic == name.Patronymic); }
        /*!
         * Put struct FullName in defined stream
         * @param[in] name name which will be put in stream
         * @return link on stream
         */
        friend std::ostream& operator << (std::ostream&, const FullName &name);
    };

    /*!
     * @brief class description person: his name, rank and experience
     */
    class Person {
    private:
        std::string rank;
        FullName name;
        uint standing;
    public:
        /*!
         * @brief Default constructor, it create class have empty field rank and name, standing is 0
         */
        Person() : standing(0) {}

        /*!
         * @brief Constructor initialize all fields of class Person
         * @param[in] _rank
         * @param[in] _name
         * @param[in] _stand
         */
        Person(std::string _rank, FullName _name, uint _stand)
        : rank(std::move(_rank)), name(std::move(_name)), standing(_stand) {}

        /*!
         * @brief Return string is rank of person
         * @return
         */
        std::string getRank() const { return rank; }

        /*!
         * @brief Return full name of person
         * @return
         */
        FullName getName() const { return name; }

        /*!
         * @brief Return standing of person (years of service in the navy)
         * @return
         */
        unsigned int getStanding() const { return standing; }

        /*!
         * @brief Change field rank
         * @param[in] _rank
         */
        void setRank(std::string _rank) { rank = std::move(_rank); }

        /*!
         * @brief Change field name
         * @param[in] _name
         */
        void setName(FullName _name) { name = std::move(_name); }

        /*!
         * @brief Change field standing (only positive number)
         * @param _standing
         */
        void setStanding(uint _standing) { standing = _standing; }

        /*!
         * @brief Compare two person
         * @param[in] person
         * @return if persons have equal all field they are equal and result is true, else false
         */
        bool operator == (const Person &person) const
        { return (rank == person.rank && name == person.name && standing == person.standing); }

        /*!
         * Put object of class Person in defined stream
         * @param[in] person person who will be put in stream
         * @return
         */
        friend std::ostream& operator << (std::ostream&, const Person &person);

    };

}

#endif //LAB4_PERSON_H
