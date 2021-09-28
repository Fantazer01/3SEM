#include "SparseMatrix.h"
#include <iostream>
#include "../../LabTools/LabTools.h"

void initializationMatrixList(ListMatrix *matrix, int n) {
    for (int i = 0; i < n; ++i) 
        matrix[i].list = nullptr;
}

void add(List **plist, int a, int j) {
    List *list = *plist;
    if (*plist == nullptr) {
        *plist = new List;
        (*plist)->a = a;
        (*plist)->next = nullptr;
        (*plist)->j = j;
    } else {
        while (list->next != nullptr) {
        list = list->next;
        }
        list->next = new List;
        list->next->next = nullptr;
        list->next->a = a;
        list->next->j = j;
    }
}

void readMatrixList(ListMatrix *matrix, int n) {
    int i, j, a;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            getNum(a);
            if (a != 0)
                add(&(matrix[i].list), a, j);

        }
    }
}

void printMatrixList(ListMatrix *matrix, int n) {
    int i, j, k;
    List *list;

    for (i = 0; i < n; ++i) {
        j = -1;
        list = matrix[i].list;
        while (list != nullptr) {
            for (k = 1; k < list->j-j; ++k) 
                std::cout << "0 ";
            j = list->j;
            std::cout << list->a << " ";
            list = list->next;
      }
      for (k = 1; k < n-j; ++k) {
          std::cout << "0 ";
      }
      std::cout << std::endl;
    }
}

void conversionToMatrixCRS(MatrixCRS &matrixCRS, ListMatrix *matrix, int n) {
    int i, j, k, counter = 0;
    List *list;

    for (i = 0; i < n; ++i) {
        list = matrix[i].list;
        while (list != nullptr) {
            list = list->next;
            ++counter;
        }
    }

    matrixCRS.size = counter;
    matrixCRS.value = new int[matrixCRS.size];
    matrixCRS.colums = new int[matrixCRS.size];
    matrixCRS.number = new int[n+1];
    matrixCRS.number[0] = 0;

    counter = 0;
    for (i = 0; i < n; ++i) {
        j = -1;
        list = matrix[i].list;
        while (list != nullptr) {
            matrixCRS.value[counter] = list->a;
            matrixCRS.colums[counter] = list->j;
            ++counter;
            list = list->next;
        }
        matrixCRS.number[i+1] = counter;
    }
}

void deleteMatrixList(ListMatrix *matrix, int n) {
    for (int i = 0; i < n; ++i) {
        List *list = matrix[i].list, *list2;
        while (list != nullptr) {
            list2 = list;
            list = list->next;
            delete list2;
        }
    }
}
