#ifndef _MY_MAT_
#define _MY_MAT_

// a constant definition exported by library:
    #define TRUE  1
// a constant definition exported by library:
    #define FALSE  0
// a constant definition exported by library:
    #define SIZE  3
// a constant definition exported by library:
    #define SIZE_VAL  9

void enterVal(int matrix[SIZE][SIZE], int values[]);
int isPathExists(int i, int j, int matrix[SIZE][SIZE]);
int bfs(int v, int dest, int n, int matrix[SIZE][SIZE]);
int shortPath(int src, int dest,int matrix[SIZE][SIZE]);


#endif