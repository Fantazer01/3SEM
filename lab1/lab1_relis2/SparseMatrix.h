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


void initializationNetMatrix(struct NetMatrix &, int);
void readNetMatrix(struct NetMatrix &);
void addNetMatrix(struct List **&, List **&, int a, int i, int j);
void printNetMatrix(struct NetMatrix &);
void computeAnswer(int *b, struct NetMatrix &matrix);
int getMaxElementFromLineNetMatrix(struct NetMatrix &matrix, int i);
void deleteNetMatrix(struct NetMatrix &);
void printAnswer(int *b, int n);

