//
// Created by oleg on 13.10.2021.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include <iostream>

namespace lab3 {
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
        std::ostream &print(std::ostream &output);
    };

    class Stack {
    private:
        static const int SZ = 100;
        int top;
        struct Data array[SZ];
    public:
        Stack():top(0){}
        Stack(int num, Data *array_data);
        int size() const {return top;}
        Conditions condition() const;
        struct Data pop();
        Stack& push(struct Data data);

        std::istream& read(std::istream &input);
        std::ostream& print(std::ostream &output);
    };


}

#endif //LAB3_STACK_H
