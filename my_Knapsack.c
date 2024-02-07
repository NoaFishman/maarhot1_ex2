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
    //scanf("%s %s %s %s %s",&items[0], &items[1], &items[2], &items[3], &items[4]);
    for (i = 0; i < RESULT; i++) {
        printf("String %d: ", i+1);
        fgets(items[i], STR_LEN, stdin);
        strtok(items[i], "\n");
        //scanf("%s", items[i]);
    }
    for (i = 0; i < RESULT; i++) {
        scanf("%d", &values[i]);
    }
    //scanf("%d %d %d %d %d",&values[0], &values[1], &values[2], &values[3], &values[4]);
    for (i = 0; i < RESULT; i++) {
        scanf("%d", &weights[i]);
    }
    //scanf("%d %d %d %d %d",&weights[0], &weights[1], &weights[2], &weights[3], &weights[4]);
    //selected_bool[RESULT]=
    knapSack(weights,values,selected_bool);
    printf("Items that give the maximum profit: [");
    int count=0;
    for(i=RESULT-1; i>=0; i--){
        if(selected_bool[i]==1){
            if(count>0){
                printf(" ,");
            }
            printf("%s", items[i]);
            count++;
            
            
        }
    }
    printf("]\n");
    // char* result[count];
    // count=0;
    // for(i=0; i<RESULT; i++){
    //     if(selected_bool[i]==1){
    //         result[count]= items[i];
    //         count++;
    //     }
    // }
    // printf("Items that give the maximum profit: [");
    // for(i=0; i<count+1;i++){
    //     printf("%s, " ,result[i]);
    // }
    // printf("]");
    return 0;





    


    
    // // Read strings from the user using scanf
    // for (i = 0; i < MAX_NUM_STRINGS; i++) {
    //     printf("String %d: ", i+1);
    //     scanf("%s", strings[i]);
    // }

    // // Display the strings
    // printf("\nEntered strings:\n");
    // for (i = 0; i < MAX_NUM_STRINGS; i++) {
    //     printf("%s\n", strings[i]);
    // }

}