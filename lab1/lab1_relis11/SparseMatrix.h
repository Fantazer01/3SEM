struct List {
    int a;
    int j;
    struct List *next;
};

struct ListMatrix {
    struct List *list;
};

struct MatrixCRS {
    int size;
    int *value;
    int *colums;
    int *number;
};

void readSparseMatrix(MatrixCRS &matrixCRS, int n);
//start list of functions for the List Matrix
void initializationMatrixList(ListMatrix *, int);
void readMatrixList(ListMatrix *, int);
void printMatrixList(ListMatrix *, int);
void conversionToMatrixCRS(MatrixCRS &matrixCRS, ListMatrix *, int);
void add(List **plist, int a, int j);
void deleteMatrixList(ListMatrix *, int);
//end list of function for the List Matrix
void computeAnswer(int *b, MatrixCRS &matrix, int n);
int getElementFromSparseMatrix(MatrixCRS &matrix, int i, int j);
int getMaxElementFromSparseMatrix(MatrixCRS &matrix, int i);
void deleteSparseMatrix(MatrixCRS &matrix);
void printAnswer(int *b, int n);


