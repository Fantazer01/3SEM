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
    std:: cout << stack2--;

    return 0;
}
