#include <bits/stdc++.h>
using namespace std;

const int MAX_NOS = 7;
int grafoComplemento[MAX_NOS][MAX_NOS] = {};
int grafo[MAX_NOS][MAX_NOS] = { {0, 1, 0, 1, 1, 1, 1},
                                {1, 0, 1, 0, 1, 0, 1},
                                {0, 1, 0, 1, 0, 1, 1},
                                {1, 0, 1, 0, 1, 1, 0},
                                {1, 1, 0, 1, 0, 0, 1},
                                {1, 0, 1, 1, 0, 0, 1},
                                {1, 1, 1, 0, 1, 1, 0}};
void complemento(int G[][MAX_NOS], int ordem, int C[][MAX_NOS]){
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            if(G[i][j]==0) C[i][j]=1;
            else if(G[i][j]==1) C[i][j]=0;
        }
    }
    printf("Grafo Informado\n");
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Grafo Complemento\n");
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}

int main(){

    complemento(grafo, MAX_NOS, grafoComplemento);

    return 0;
}