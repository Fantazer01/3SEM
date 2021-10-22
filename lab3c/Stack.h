//
// Created by oleg on 13.10.2021.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include <iostream>

namespace lab3c {
    #define SIZE_STR 81

    enum Conditions {
        CON_EMPTY,
        CON_PARTIALLY,
        CON_FULL,
    };

    struct Data {
    public:
        int a;
        char s[SIZE_STR];
        Data():a(0) {*s='\0';}
        Data(int arg):a(arg) {*s='\0';}
        Data(char *s);
        Data(int arg, char *s);
        std::istream &read(std::istream &);
        std::ostream &print(std::ostream &output) const;
    };

    class Stack {
    private:
        static const int Step = 5;
        int SZ;
        int top;
        struct Data *array;

        void Swap(Data &val1, Data &val2) {
            Data data_temp = val1;
            val1 = val2;
            val2 = data_temp;
        }

    public:
        Stack():SZ(Step), top(0), array(new Data[Step]){}
        Stack(int num, Data *array_data);
        Stack(const Stack &stack);//copy
        Stack(Stack && stack) noexcept ;//move
        ~Stack() {delete [] array;}

        int size() const {return top;}
        Conditions condition() const;
        struct Data pop();
        Stack& push(Data data);

        Stack operator +(const Stack &stack) const;
        Stack& operator =(const Stack &stack);
        Stack& operator =(Stack &&stack);
        Stack& operator +=(const Stack &stack);
        Stack& operator --();
        const Stack operator --(int);
        Stack operator ~();
        Data& operator [](int i) const;
        Stack& operator ()(Data data);

        std::istream& read(std::istream &input);
        std::ostream& print(std::ostream &output) const;

        friend std::istream& operator >>(std::istream &, Stack &);
        friend std::ostream& operator <<(std::ostream &, const Stack &);

    };


}

#endif //LAB3_STACK_H
