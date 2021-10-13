//
// Created by oleg on 13.10.2021.
//

#include "Stack.h"

namespace lab3 {

    //data

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

    std::istream &Data::read(std::istream &input) {
        //simple cod
        input >> a >> s;
        //hard cod
        //soon it will be here
        return input;
    }

    std::ostream &Data::print(std::ostream &output) {
        output << a << " " << s << " ";
        return output;
    }

    //stack

    struct Data Stack::pop() {
        if (top <= 0)
            throw "stack is empty";
        --top;
        return array[top];
    }

    Stack::Stack(int num, Data *array_data): top(0) {
        if (num < 0)
            throw "incorrect value of number";
        if (num > SZ)
            throw "stack size is not enough";
        for (; top < num; ++top) {
            array[top] = array_data[top];
        }
    }

    Stack& Stack::push(struct Data data) {
        if (top >= SZ)
            throw "stack is full";
        array[top] = data;
        ++top;
        return *this;
    }

    std::istream& Stack::read(std::istream &input) {
        Data data;
        data.read(input);
        (*this).push(data);
        return input;
    }

    std::ostream& Stack::print(std::ostream &output) {
        for(int i = 0; i < top; ++i)
            array[i].print(output);
        return output;
    }
/*
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
*/
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