//
// Created by oleg on 13.10.2021.
//

//r-l-value

#include "Stack.h"

namespace lab3c {

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

    Stack::Stack(int num, Data *array_data): SZ(0), top(0), array(nullptr) {
        if (num < 0)
            throw "incorrect value of number";

        SZ = num;
        array = new Data[SZ];

        for (; top < num; ++top)
            array[top] = array_data[top];
    }

    Stack::Stack(const Stack &stack):SZ(stack.SZ), top(stack.top) {
        array = new Data[SZ];
        for (int i = 0; i < top; ++i)
            array[i] = stack.array[i];
    }

    Stack::Stack(Stack && stack) noexcept:SZ(stack.SZ), top(stack.top), array(stack.array) {
        stack.array = nullptr;

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
        if (top >= SZ) {
            Data *old_array = array;
            SZ += Step;
            array = new Data[SZ];
            for (int i = 0; i < top; ++i)
                array[i] = old_array[i];
            delete [] old_array;
        }

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

    Stack Stack::operator +(const Stack &stack) const{
        if (top+stack.top >= SZ)
            throw "there is not enough space on the stack";

        Stack stack2 = *this;

        for (int i = 0; i < stack.top; ++i, ++(stack2.top))
            stack2.array[stack2.top] = stack.array[i];

        return stack2;
    }

    Stack& Stack::operator =(const Stack &stack) {
        if (this != &stack) {
            SZ = stack.SZ;
            top = stack.top;

            delete[] array;
            array = new Data[SZ];

            for (int i = 0; i < top; ++i)
                array[i] = stack.array[i];
        }

        return *this;
    }

    Stack& Stack::operator =(Stack &&stack) {
        if (this != &stack) {
            int temp = SZ;
            SZ = stack.SZ;
            stack.SZ = temp;

            temp = top;
            top = stack.top;
            stack.top = temp;

            Data *temp_ar = array;
            array = stack.array;
            stack.array = temp_ar;
        }

        return *this;
    }

    Stack& Stack::operator +=(const Stack &stack) {
        if (top+stack.top >= SZ) {
            Data *old_array = array;
            SZ += stack.SZ;
            array = new Data[SZ];
            for (int i = 0; i < top; ++i)
                array[i] = old_array[i];
            delete [] old_array;
        }

        for (int i = 0; i < stack.top; ++i, ++top)
            array[top] = stack.array[i];

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

    Stack Stack::operator ~() {
        Stack stack2(*this);
        int i, j = top - 1;
        for (i = 0; i < j; ++i, --j)
            Swap(stack2.array[i], stack2.array[j]);

        return stack2;
    }

//rvalue lvalue
    Data& Stack::operator [](int i) const {
        if (i < 0 || i >= top)
            throw "incorrect index";
        return array[i];
    }

    Stack& Stack::operator ()(Data data) {
        push(data);
        return *this;
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