#include <iostream>
#include <ctime>
#include "SparseMatrix.h"
#include "../../LabTools/LabTools.h"


int main() {
    int n;
    NetMatrix matrix{0, nullptr, nullptr};

    try {
        getNum(n);
        int b[n];

        clock_t start;
        start = clock();
        initializationNetMatrix(matrix, n);
        try {
            readNetMatrix(matrix);
            printNetMatrix(matrix);
            computeAnswer(b, matrix);
            deleteNetMatrix(matrix);
            printAnswer(b, n);
        } catch (char const* str) {
            std::cout << str << std::endl;
        }
        std::cout << "Time work: " << clock() - start << std::endl;
    } catch (char const* str) {
        std::cout << "Sorry, EOF..." << std::endl;
    }

    return 0;
}
