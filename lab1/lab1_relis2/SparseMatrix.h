struct List {
    int a;
    int i;
    int j;
    struct List *next_l;
    struct List *next_c;
};

struct NetMatrix {
    int size;
    struct List **list_lines;
    struct List **list_colums;
};


void initializationNetMatrix(NetMatrix &, int);
void readNetMatrix(NetMatrix &);
void addNetMatrix(List **&, List **&, int a, int i, int j);
void printNetMatrix(NetMatrix &);
void computeAnswer(int *b, NetMatrix &matrix);
int getMaxElementFromLineNetMatrix(NetMatrix &matrix, int i);
void deleteNetMatrix(NetMatrix &);
void printAnswer(int *b, int n);

