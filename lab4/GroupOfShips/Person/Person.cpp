//
// Created by oleg on 10.11.2021.
//

/*!
 * @file
 * @brief executable friend operator <<, >> for FullName and Person
 */

#include "Person.h"
#include <stdexcept>
#include <iostream>

namespace lab4 {
    std::ostream& operator << (std::ostream& output, const FullName &name) {
        output << name.First_name << " " << name.Last_name << " " << name.Patronymic;
        return output;
    }

    std::ostream& operator << (std::ostream& output, const Person &person) {
        output << person.rank << " " << person.name << " standing " << person.standing;
        return output;
    }
}