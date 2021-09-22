#include <iostream>
#include <ctime>
#include "SparseMatrix.h"

int main() {
    
    int n;
    MatrixCRS matrix;
    std::cin >> n;
    int b[n];

    clock_t start = clock();
    
    readSparseMatrix(matrix, n);
    computeAnswer(b, matrix, n);
    deleteSparseMatrix(matrix);
    //printAnswer(b, n);
    std::cout << clock() - start << std::endl;
    

    return 0;
}
