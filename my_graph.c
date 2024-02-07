#include "my_mat.h"
#include  <stdio.h>
#include <limits.h>

int main(){
    char y='A';
    int x[SIZE][SIZE];
    int src, dest;
    while(y!='D'){
        y=getchar();
        if(y=='A'){
            getMatrix(x);
        }
        if(y=='B'){
            scanf("%d %d",&src ,&dest);
            isPath(src, dest, x);
        }
        if(y=='C'){
            scanf("%d %d",&src ,&dest);
            int ans= shortestPath(src, dest, x);
            printf("%d\n",ans);
        }
    }
    return 0;
}