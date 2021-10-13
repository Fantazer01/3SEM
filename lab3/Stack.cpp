//
// Created by oleg on 13.10.2021.
//

#include "Stack.h"

namespace lab3 {

    Data::Data(char *s) {
        a = 0;
        char *p = s;
        for (int i = 0; *s != '\0' && i != SIZE_STR-1; ++i, ++s, ++p)
            *p = *s;
        *p = '\0';
    }

    Data::Data(int arg, char *str) {
        a = arg;
        char *p = s;
        for (int i = 0; *str != '\0' && i != SIZE_STR-1; ++i, ++str, ++p)
            *p = *str;
        *p = '\0';
    }

    struct Data Stack::pop() {
        if (top <= 0)
            throw "stack is empty";
        --top;
        return array[top];
    }

    Stack& Stack::push(struct Data data) {
        if (top >= SZ)
            throw "stack is full";
        array[top] = data;
        ++top;
        return *this;
    }

    std::istream& Stack::read(std::istream &input) {
        int a;
        char s[SIZE_STR];
        input >> a >> s;
        (*this).push(a, s);
        return input;
    }

    std::ostream& Stack::print(std::ostream &output) {
        for(int i = 0; i < top; ++i)
            output << array[i].a << " " << array[i].s << " ";
        return output;
    }

    std::ostream& Stack::printInt(std::ostream &output) {
        for(int i = 0; i < top; ++i)
            output << array[i].a << " ";
        return output;
    }

    std::ostream& Stack::printStr(std::ostream &output) {
        for(int i = 0; i < top; ++i)
            output << array[i].s << " ";
        return output;
    }

    /*
    Stack::Stack(int a, char *s) {
        array[top].a = a;
        char *p = array[top].s;
        for (int i = 0; *s != '\0' && i != SIZE_STR-1; ++i, ++s, ++p)
            *p = *s;
        *p = '\0';
        ++top;
    }
*/

/*
    Stack& Stack::push(int a, char *s) {
        if (top >= SZ)
            throw "stack is full";
        if (s == nullptr)
            throw "string is nullptr";
        array[top].a = a;
        char *p = array[top].s;
        for (int i = 0; *s != '\0' && i != SIZE_STR-1; ++i, ++s, ++p)
            *p = *s;
        *p = '\0';
        ++top;
        return *this;
    }

    Stack& Stack::push(int a) {
        if (top >= SZ)
            throw "stack is full";
        array[top].a = a;
        *(array[top].s) = '\0';
        ++top;
        return *this;
    }
*/

}