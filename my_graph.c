#include <stdio.h>
#include "my_mat.h"

int main() {
    int matrix[SIZE][SIZE];
    int values[SIZE_VAL];
    char letter;
    int flag = TRUE;

    while (flag)
    {
        //scanf("Enter a letter A, B, C, D: %c", &letter);
        printf("Enter a letter A, B, C, D: ");
        scanf(" %c", &letter);
    switch (letter) {
        case 'A':
    // Get the values from the user
        for (int i = 0; i < SIZE_VAL; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &values[i]);
        }
        enterVal(matrix, values);
        break;
        case 'B':
            int i, j;
            scanf("%d %d", &i,&j);
            int result = isPathExists(i, j, matrix);
            if(result == TRUE){
                printf("TRUE\n");
             } else {
                 printf("FALSE\n");
            }
            break;
        case 'C':
            int k ,l;
            scanf("%d %d", &k,&l);
            int shortest = shortPath(k,l,matrix);
            printf("%d\n", shortest);
            break;
        case 'D':
            flag = FALSE;
            break;
        }
        if(letter == EOF){
            break;
        }
    }

    return 0;
}
