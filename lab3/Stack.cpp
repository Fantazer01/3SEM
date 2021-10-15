//
// Created by oleg on 13.10.2021.
//

//потоки - готово
//бинарный - готово
//инкремент или дикремент - готово
//инверсия
//индексация
//модифцир присваивание
//() приведение типа space ship

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

    std::ostream &Data::print(std::ostream &output) const{
        output << a << " " << s << " ";
        return output;
    }

    //stack

    Stack::Stack(int num, Data *array_data): top(0) {
        if (num < 0)
            throw "incorrect value of number";
        if (num > SZ)
            throw "stack size is not enough";
        for (; top < num; ++top) {
            array[top] = array_data[top];
        }
    }

    Conditions Stack::condition() const {
        if (top == 0)
            return CON_EMPTY;
        else if (top == SZ)
            return CON_FULL;
        return CON_PARTIALLY;
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
        Data data;
        data.read(input);
        (*this).push(data);
        return input;
    }

    std::ostream& Stack::print(std::ostream &output) const {
        for(int i = 0; i < top; ++i)
            array[i].print(output);
        return output;
    }

    const Stack& Stack::operator +(Data data) {
        if (top >= SZ)
            throw "stack is full";
        array[top] = data;
        ++top;
        return *this;
    }

    Stack& Stack::operator --() {
        pop();
        return *this;
    }

    const Stack Stack::operator --(int) {
        Stack x(*this);
        pop();
        return x;
    }
//rvalue lvalue
    Data Stack::operator [](int i) {
        if (i < 0 || i >= top)
            throw "incorrect index";
        return array[i];
    }

    std::istream& operator >>(std::istream &input, Stack &stack) {
        Data data;
        data.read(input);
        stack.push(data);
        return input;
    }

    std::ostream& operator <<(std::ostream &output, const Stack &stack) {
        for(int i = 0; i < stack.top; ++i)
            stack.array[i].print(output);
        return output;
    }

}