#include <iostream>
#include <ctime>
#include "SparseMatrix.h"
#include "../../LabTools/LabTools.h"

int main() {
    int n;
    MatrixCRS matrix{0, nullptr, nullptr};

    try {
        getNum(n);
        int b[n];

        clock_t start;
        start = clock();
        try {
            readSparseMatrix(matrix, n);
            computeAnswer(b, matrix, n);
            deleteSparseMatrix(matrix);
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
