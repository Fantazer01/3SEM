#include <iostream>
#include <ctime>
#include "SparseMatrix.h"


int main() {
    int n;
    NetMatrix matrix;
    std::cin >> n;
    int b[n];

    clock_t start = clock();
    initializationNetMatrix(matrix, n);
    readNetMatrix(matrix);
    //printNetMatrix(matrix);
    computeAnswer(b, matrix);
    deleteNetMatrix(matrix);
    //printAnswer(b, n);
    std::cout << clock() - start << std::endl;

    return 0;
}

void initializationNetMatrix(NetMatrix &matrix, int n) {
    int i;

    matrix.size = n;
    matrix.list_lines = new List*[n];
    matrix.list_colums = new List*[n];

    for (i = 0; i < n; ++i) {
        matrix.list_lines[i] = nullptr;
        matrix.list_colums[i] = nullptr;
    }
}

void readNetMatrix(NetMatrix &matrix) {
    int i, j, a;
    List **plistL[matrix.size], **plistC[matrix.size];

    for (i = 0; i < matrix.size; ++i) {
        plistL[i] = matrix.list_lines+i;
        plistC[i] = matrix.list_colums+i;
    }

    for (i = 0; i < matrix.size; ++i) {
        for (j = 0; j < matrix.size; ++j) {
            std::cin >> a;
            if (a != 0) 
                addNetMatrix(plistL[i], plistC[j], a, i, j);
        }
    }
}

void addNetMatrix(List **&plistL, List **&plistC, int a, int i, int j) {
    List *list = new List;

    list->a = a;
    list->i = i;
    list->j = j;
    list->next_l = nullptr;
    list->next_c = nullptr;

    *plistL = list;
    *plistC = list;
    plistL = &(list->next_l);
    plistC = &(list->next_c);

}

void printNetMatrix(NetMatrix &matrix) {
    int i, j, k;
    List *list;

    std::cout << "Original matrix:\n";

    for (i = 0; i < matrix.size; ++i) {
        j = -1;
        list = matrix.list_lines[i];
        while (list != nullptr) {
            for (k = 1; k < list->j-j; ++k) 
                std::cout << "0 ";
            j = list->j;
            std::cout << list->a << " ";
            list = list->next_l;
      }
      for (k = 1; k < matrix.size-j; ++k) {
          std::cout << "0 ";
      }
      std::cout << std::endl;
    }
}

void computeAnswer(int *b, NetMatrix &matrix) {
    int i, j, k, a;

    List *plistL, *plistC;
    

    for (i = 0; i < matrix.size; ++i) {
        b[i] = 0;
        k = getMaxElementFromLineNetMatrix(matrix, i);
        plistL = matrix.list_lines[i];
        plistC = matrix.list_colums[k];

        for (j = 0; j < matrix.size; ++j) {
            while (plistL != nullptr && plistL->j < j)
                plistL = plistL->next_l;
            while (plistC != nullptr && plistC->i < j)
                plistC = plistC->next_c;
            if (plistL == nullptr || plistC == nullptr)
                break;
            if (plistL->j == j && plistC->i == j)
                b[i] += plistL->a*plistC->a;
        }
    }
}

int getMaxElementFromLineNetMatrix(NetMatrix &matrix, int i) {
    List *list = matrix.list_lines[i];
    
    int max = 0;
    int maxIndex = 0;
    int j = -1;

    if (matrix.list_lines[0] != nullptr && matrix.list_lines[0]->j == 0) {
        max = matrix.list_lines[0]->a;
    }

    while(list != nullptr) {
        if (list->a > max) {
            max = list->a;
            maxIndex = list->j;
        }
        list = list->next_l;
    }
    if (max < 0) {
        list = matrix.list_lines[i];
        while(list != nullptr && list->j-j > 1) {
            j = list->j;
            list = list->next_l;
        }
        if (j+1 != matrix.size)
            return j+1;
    }
    return maxIndex;
}

void deleteNetMatrix(NetMatrix &matrix) {
    int i;
    List *list, *list2;

    for (i = 0; i < matrix.size; ++i) {
        list = matrix.list_lines[i];
        while (list != nullptr) {
            list2 = list;
            list = list->next_l;
            delete list2;
        }
    }

    delete [] matrix.list_lines;
    delete [] matrix.list_colums;
}

void printAnswer(int *b, int n) {
    int i;
    std::cout << "Answer: ";
    for (i = 0; i < n; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
}

