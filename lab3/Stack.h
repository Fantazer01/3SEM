//
// Created by oleg on 13.10.2021.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include <iostream>

namespace lab3 {
    #define SIZE_STACK 100
    #define SIZE_STR 81

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
        //Stack(Data data) {array[top] = data; ++top;}
        //Stack(int a, char *s);
        int size() const {return top;}
        bool empty() const {return top == 0;}
        bool full() const {return top == SZ;}
        struct Data pop();
        Stack& push(struct Data data);
        /*
        Stack& push(int a, char *s);
        Stack& push(int a);
         */

        std::istream& read(std::istream &input);
        std::ostream& print(std::ostream &output);
        std::ostream& printInt(std::ostream &output);
        std::ostream& printStr(std::ostream &output);

    };


}

#endif //LAB3_STACK_H
