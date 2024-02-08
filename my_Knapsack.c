#include <stdio.h>
#include "my_mat.h"


int main() {
    char items[ITEMS];
    int values[ITEMS];
    int weights[ITEMS] = {0};
    int selected_bool[ITEMS];
  
    for(int i = 0; i < ITEMS; i++) {
        // printf("item %d: ", i+1);
        scanf(" %c", &items[i]);  
        // printf("value %d: ", i+1);
        scanf("%d", &values[i]);
        // printf("weight %d: ", i+1);
        scanf("%d", &weights[i]);
        getchar();
    }

    int result = knapSack(weights,values,selected_bool);
    printf("Maximum profit: %d\n", result);

    printf("Selected items: ");
    int last_selected_index = -1; // מסמן את האינדקס האחרון שבו התו נבחר

    for (int i = 0; i < ITEMS; i++) {
      if (selected_bool[i] == 1) {
           printf("%c", items[i]);
           last_selected_index = i;
           if (i < ITEMS - 1) {
            printf(" ");
          }
        }
    }

    if (last_selected_index != -1) {
    printf("\n"); // ירד לשורה הבאה אם יש תווים שנבחרו
    }


    return 0;
}
