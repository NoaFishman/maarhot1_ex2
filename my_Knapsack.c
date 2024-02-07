#include  <stdio.h>
#include <limits.h>
#include <string.h>
#define LIM_W 20
#define RESULT 5
#define STR_LEN 20

int max(int x, int y) {
    return (x > y) ? x : y;
}

int knapSack(int weights[], int values[] , int selected_bool[]){
    int table[LIM_W+1][RESULT+1]; 
    int i, w;

     for (i = 0; i <= RESULT; i++) {
        for (w = 0; w <= LIM_W; w++) {
            if (i == 0 || w == 0)
                table[w][i] = 0;
            else if (weights[i - 1] <= w)
                table[w][i] = max(values[i - 1] + table[w - weights[i - 1]][i - 1], table[w][i - 1]);
            else
                table[w][i] = table[w][i - 1];
        }
    }

    int maxProfit = table[LIM_W][RESULT];
    w = LIM_W;

     for (i = RESULT; i > 0; i--) {
        if (table[w][i] > table[w][i - 1]) {
            int wt = weights[i - 1];
            selected_bool[i - 1] = 1;
            w = w - wt;
        }
    }

     printf("Maximum profit: %d\n", maxProfit);
    return maxProfit;



}

int main(){
    char items[RESULT][STR_LEN];
    int weights[RESULT], values[RESULT], selected_bool[RESULT]={0,0,0,0,0};
    int i;
    
    for (i = 0; i < RESULT; i++) {
         scanf("%s %d %d", items[i], &values[i], &weights[i]);
        //printf("String %d: ", i+1);
        // fgets(items[i], STR_LEN, stdin);
        // strtok(items[i], " ");
        // //scanf("%s", &items[i]);
        // scanf("%d", &values[i]);
        // scanf("%d", &weights[i]);
        
    }
    // for (i = 0; i < RESULT; i++) {
    //     scanf("%d", &values[i]);
    // }
    
    // for (i = 0; i < RESULT; i++) {
    //     scanf("%d", &weights[i]);
    // }
    
    
    knapSack(weights,values,selected_bool);
    printf("\nSelected items:");
    //int count=0;
    for(i=0; i<RESULT; i++){
        if(selected_bool[i]==1){
            
            printf(" %s", items[i]);
        }
    }
    printf("\n\n");
    return 0;


}