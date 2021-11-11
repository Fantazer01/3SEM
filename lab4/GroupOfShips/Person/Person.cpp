//
// Created by oleg on 10.11.2021.
//

#include "Person.h"
#include <stdexcept>

namespace lab4 {
    void Person::setStanding(int _standing) {
        if (_standing < 0)
            throw std::invalid_argument("invalid value!");
        standing = _standing;
    }
}