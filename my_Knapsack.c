#include <stdio.h>
#include "my_mat.h"


int main() {
    char items[ITEMS];
    int values[ITEMS];
    int weights[ITEMS] = {0};
    int selected_bool[ITEMS];
  
    for(int i = 0; i < ITEMS; i++) {
        printf("item %d: ", i+1);
        scanf(" %c", &items[i]);  // שימוש ברווח לפני %c
        printf("value %d: ", i+1);
        scanf("%d", &values[i]);
        printf("weight %d: ", i+1);
        scanf("%d", &weights[i]);
        getchar();  // קריאה נוספת לסיום השורה
    }

    int result = knapSack(weights,values,selected_bool);
    printf("Maximum profit: %d\n", result);

    printf("Selected items: ");
    for (int i = 0; i < ITEMS; i++) {
        if (selected_bool[i] == 1) {
            printf("%c ", items[i]);
        }
    }


    return 0;
}
