#include "my_mat.h"
#include <stdbool.h>
#include <limits.h>

void enterVal(int matrix[SIZE][SIZE], int values[]){
    int index = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
           matrix[i][j] = values[index++];
        }
    }
}

int isPathExists(int i, int j, int matrix[SIZE][SIZE]){
//    int path = bfs(i,j,SIZE,matrix);
    int path = shortPath(i,j,matrix);
   if(path == -1){
    return False;
   }
    return True;
}
int bfs(int v, int dest, int n, int matrix[SIZE][SIZE]) {
    bool visited[SIZE];
    // Create a queue and enqueue the source vertex
    int queue[SIZE], front = 0, rear = 0;
    queue[rear++] = v;
    // Mark the vertex as visited
        visited[v] = true;


    while (front != rear) {
        v = queue[front++];

        // If this vertex is the destination, we found a path
        if (v != dest) {
            return 1;
        }
        if (v == dest) {
            return 0;
        }


        
        // Enqueue all adjacent vertices that have not been visited yet
        for (int i = 0; i < n; i++) {
            if (matrix[v][i] != 0 && !visited[i]) {
                //  if (rear >= SIZE) {
                //     return 0;
                // }
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    // If we reach here, there is no path from v to dest
    return 0;
}

int shortPath(int src, int dest, int matrix[SIZE][SIZE]){
   int dist[SIZE][SIZE], i, j, k; 
  
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++){ 
            dist[i][j] = matrix[i][j];
        }
    } 
  
    for (k = 0; k < SIZE; k++) 
    { 
        for (i = 0; i < SIZE; i++) 
        { 
            for (j = 0; j < SIZE; j++) 
            { 
                if (i!=j && dist[i][j] == 0 && dist[i][k] != 0 && dist[k][j] != 0)
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                if (dist[i][j] != 0 && dist[i][k] != 0 && dist[k][j] != 0)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j]){ 
                        dist[i][j] = dist[i][k] + dist[k][j];
                    } 
                }
                
                
            } 
        } 
    } 
     if (dist[src][dest] == 0){
        return -1;
     }
    else{
        return dist[src][dest];
    }
}

int knapSack(int weights[], int values[] , int selected_bool[]){

    int K[ITEMS + 1][WEIGHT_BAG + 1]; 
   
    for (int i = 0; i <= ITEMS; i++) { 
        for (int w = 0; w <= WEIGHT_BAG; w++) { 
            if (i == 0 || w == 0){ 
                K[i][w] = 0;
            } 
            else if (weights[i - 1] <= w) {
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            }
            else{
                K[i][w] = K[i - 1][w]; 
            }
        } 
    }
    int result = K[ITEMS][WEIGHT_BAG];
    int res = K[ITEMS][WEIGHT_BAG];

    int w = WEIGHT_BAG;
    for (int i = ITEMS; i > 0 && res > 0; i--) {
         
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means 
        // the item is included.
        if (res == K[i - 1][w]) 
            continue;        
        else {
 
            // This item is included.
            selected_bool[i-1] = 1;
             
            // Since this weight is included its 
            // value is deducted
            res = res - values[i - 1];
            w = w - weights[i - 1];
        }
    }
      
    return result; 
}
int max(int a, int b) { return (a > b) ? a : b; }
