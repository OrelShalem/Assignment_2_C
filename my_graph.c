#include <stdio.h>
#include "my_mat.h"

int main() {
    int matrix[SIZE][SIZE];
    int values[SIZE_VAL];
    char letter;
    int flag = True;

    while (flag)
    {
        //scanf("Enter a letter A, B, C, D: %c", &letter);
        scanf(" %c", &letter);
    switch (letter) {
        case 'A':
    // Get the values from the user
        for (int i = 0; i < SIZE_VAL; i++) {
        scanf("%d", &values[i]);
        }
        enterVal(matrix, values);
        break;
        case 'B':
            int i, j;
            scanf("%d %d", &i,&j);
            int result = isPathExists(i, j, matrix);
            if(result == True){
                printf("True\n");
             } else {
                 printf("False\n");
            }
            break;
        case 'C':
            int k ,l;
            scanf("%d %d", &k,&l);
            int shortest = shortPath(k,l,matrix);
            printf("%d\n", shortest);
            break;
        case 'D':
            flag = False;
            break;
        }
        if(letter == EOF){
            break;
        }
    }

    return 0;
}
