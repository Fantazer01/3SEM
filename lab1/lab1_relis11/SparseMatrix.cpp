#include "SparseMatrix.h"
#include <iostream>

void readSparseMatrix(MatrixCRS &matrixCRS, int n) {
    int i, j, k;
    ListMatrix matrix[n];

    initializationMatrixList(matrix, n);
    try {
        readMatrixList(matrix, n);
        //printMatrixList(matrix, n);
        conversionToMatrixCRS(matrixCRS, matrix, n);
    } catch (char const* str) {
        std::cout << "Sorry, EOF..." << std::endl;
        deleteMatrixList(matrix, n);
        throw "Matrix isn't entered";
    }

    deleteMatrixList(matrix, n);
}

void computeAnswer(int *b, MatrixCRS &matrix, int n) {
    int i, j, k, a;

    for (i = 0; i < n; ++i) {
        b[i] = 0;
        k = getMaxElementFromSparseMatrix(matrix, i);
        for (j = 0; j < n; ++j) {
            if ((a = getElementFromSparseMatrix(matrix, i, j)) != 0)
                b[i] += a * getElementFromSparseMatrix(matrix, j, k);
        }
    }
}

int simpleSearch(MatrixCRS &matrix, int start, int finish, int j) {
    int k;

    for(k = start; k < finish; ++k) {
        if (matrix.colums[k] == j)
            return matrix.value[k];
        else if (matrix.colums[k] > j)
            return 0;
    }
    return 0;
}

int binSearch(MatrixCRS &matrix, int start, int finish, int j) {
    int k;

    if (matrix.colums[start] > j || matrix.colums[finish] < j) 
        return 0;
    if (matrix.colums[start] == j) 
        return matrix.value[start];
    if (matrix.colums[finish] == j)
        return matrix.value[finish];
    

    while (finish - start > 1) {
        k = (start+finish) / 2;
        if (matrix.colums[k] == j) {
            return matrix.value[k];
        } else if (matrix.colums[k] > j) {
            finish = k;
        } else {
            start = k;
        }
    }

    return 0;
}

int getElementFromSparseMatrix(MatrixCRS &matrix, int i, int j) {
    int start = matrix.number[i];
    int finish = matrix.number[i+1];

    //int a = 0, b = 0;


    //a = simpleSearch(matrix, start, finish, j);
    //b = binSearch(matrix, start, finish-1, j);
    //std::cout << (a == b) << std::endl;
    /*
    for (int k = start; k < finish; ++k) {
        if (matrix.colums[k] == j)
            return matrix.value[k];
        else if (matrix.colums[k] > j)
            return 0;
    }
    */

    return simpleSearch(matrix, start, finish, j);
}


int getMaxElementFromSparseMatrix(MatrixCRS &matrix, int i) {
    int start = matrix.number[i];
    int finish = matrix.number[i+1];
    int max;
    int maxIndex = 0;
    int k, j;

    if (start != finish && matrix.colums[start] == 0) {
        max = matrix.value[start];
    } else {
        max = 0;
    }

    for (k = start; k < finish; ++k) {
        if (max < matrix.value[k]) {
            max = matrix.value[k];
            maxIndex = matrix.colums[k];
        }
    }

    if (max < 0) {
        j = -1;
        for (k = start; k < finish && matrix.colums[k]-j > 1; ++k) {j = matrix.colums[k];}
        if (j+1 != matrix.size)
            return j+1;
    }

    return maxIndex;
}

void deleteSparseMatrix(MatrixCRS &matrix) {
    delete [] matrix.value;
    delete [] matrix.colums;
    delete [] matrix.number;
}

void printAnswer(int *b, int n) {
    int i;
    std::cout << "Answer: ";
    for (i = 0; i < n; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
}


