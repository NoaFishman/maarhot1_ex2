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
    //int previus[SIZE];
    int sptSet[SIZE];
    int i=0;
    
    for(i=0; i<SIZE;i++){
        dis[i] = INT_MAX;
        sptSet[i] = 0;
        //previus[i] = -1;
    }
    dis[sorce]=0;
    int count=0;

    for (count = 0; count < SIZE - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dis, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;
        int i=0;
        // Update dist value of the adjacent vertices of the picked vertex.
        for (i = 0; i < SIZE; i++) {
            // Update dist[v] only if it is not in the sptSet, there is an edge from u to v,
            // and the total weight of the path from src to v through u is less than the current value of dist[v]
            if (!sptSet[i] && x[u][i] && dis[u] != INT_MAX && dis[u]+x[u][i] < dis[i]) {
                dis[i] = dis[u] + x[u][i];
               // previus[i] = u;
            }
        }
    }
    if(dis[dest]== INT_MAX|| dis[dest]==0){
        return -1;
    }

 return dis[dest];
}

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
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