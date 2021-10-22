#include <iostream>
#include "Stack.h"

using namespace lab3c;

Stack PUSH(Stack stack) {
    stack.push(3);
    return stack;
}

int main() {
    Data data[2];
    data[0].a = 1;
    data[1].a = 2;

    Stack stack(2, data);
    Stack stack2 = PUSH(stack);

    stack2[1] = Data(4);
    std:: cout << stack2 << std::endl;

    Stack stack3 = stack = stack2;

    const Stack stack4(2, data);

    std::cout << stack << std::endl << stack2 << std::endl << stack3 << std::endl;

    std::cout << stack4 << std::endl;

    return 0;
}
