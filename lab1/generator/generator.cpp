#include <iostream>
#include <ctime>

int main() {
    int n, i, j, a, counter = 0;

    std::cin >> n;

    std::cout << n << std::endl;

    srand(time(0));

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            //a = rand()%8;
            a = 0;
            if (a < 7)
                a = 0;
            else
                a = 1;
            counter += a;
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
    std::cout << counter;

    return 0;
}
