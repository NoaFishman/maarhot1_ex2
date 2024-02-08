#include "my_mat.h"
#include  <stdio.h>
#include <limits.h>

void getMatrix(int x[][SIZE]){
    int i=0,j=0,a;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            scanf("%d ", &a);
            x[i][j]=a;
        }
    }
}

void isPath(int i, int j,int x[][SIZE]){
    int ans=shortestPath(i,j, x);
    if(ans==(-1)||ans==0){
        printf("False\n");
    }
    else{
        printf("True\n");
    }
}

int shortestPath(int sorce, int dest, int x[][SIZE]){
    int dis[SIZE];
    int sptSet[SIZE];
    int i=0;
    
    for(i=0; i<SIZE;i++){
        dis[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dis[sorce]=0;
    int count=0;

    for (count = 0; count < SIZE - 1; count++) {
        int u = minDistance(dis, sptSet);

        sptSet[u] = 1;
        int i=0;
        for (i = 0; i < SIZE; i++) {
            if (!sptSet[i] && x[u][i] && dis[u] != INT_MAX && dis[u]+x[u][i] < dis[i]) {
                dis[i] = dis[u] + x[u][i];
            }
        }
    }
    if(dis[dest]== INT_MAX|| dis[dest]==0){
        return -1;
    }

 return dis[dest];
}

int minDistance(int dis[], int sptSet[]) {
    int min = INT_MAX, min_index;
    int i=0;
    for (i = 0; i < SIZE; i++) {
        if (sptSet[i] == 0 && dis[i] <= min) {
            min = dis[i];
            min_index = i;
        }
    }

    return min_index;
}