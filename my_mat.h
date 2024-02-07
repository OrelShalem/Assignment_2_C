#ifndef _MY_MAT_
#define _MY_MAT_

// a constant definition exported by library:
    #define TRUE  1
// a constant definition exported by library:
    #define FALSE  0
// a constant definition exported by library:
    #define SIZE  10
// a constant definition exported by library:
    #define SIZE_VAL  100
// a constant definition exported by library:
    #define ITEMS  5
// a constant definition exported by library:
    #define WEIGHT_BAG  20

void enterVal(int matrix[SIZE][SIZE], int values[]);
int isPathExists(int i, int j, int matrix[SIZE][SIZE]);
int bfs(int v, int dest, int n, int matrix[SIZE][SIZE]);
int shortPath(int src, int dest,int matrix[SIZE][SIZE]);
int knapSack(int weights[], int values[], int selected_bool[]);
int max(int a, int b);

#endif
