#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Menu.h"

int main() {
    const char *msgs[] = {"Quit", "Add element to stack from input stream", "Get elements from stack to output stream"};
    const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
    int (*fptr[NMsgs])(lab3::Stack &) = {nullptr, addToStack, getFromStack};
    lab3::Stack stack;
    int rc = 0;

    std::cout << "Hello, dear user!" << std::endl;

    while ((rc = dialog(msgs, NMsgs))) {
        if (!fptr[rc](stack))
            break;
        std::cout<< "Что-то делаем\n";
        std::cin.get();
        std::cin.get();
        system("clear");
    }
    std::cout << "Game over" << std::endl;

    /*
    lab3::Data data{1, "oleg"}, data2;
    lab3::Stack stack;
    stack.push(data);

    data2 = stack.pop();
    std::cout << data2.a << " " << data2.s << std::endl;
    try {
        data2 = stack.pop();
        std::cout << data2.a << " " << data2.s << std::endl;
    } catch (const char *str) {
        std::cout << str << std::endl;
    }
    lab3::Data data3{-5, "one"};
    strcpy(data2.s, "two");
    strcpy(data.s, "three");
    stack.push(data3);
    stack.push(data2);
    stack.push(data);
    std::cout << stack.size() << std::endl;
    stack.print(std::cout);
    std::cout << std::endl;

    lab3::Stack stack2{};
    stack2.read(std::cin);
    stack2.print(std::cout);
    */
    return 0;
}
