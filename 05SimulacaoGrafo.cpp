#include <bits/stdc++.h>
using namespace std;

#define MAX 100
struct no { int v; int g; };

void prova (int G[][MAX], int ordem){
    int Xs[ordem], S[ordem];
    int x = 1, fim = -1, card, aux, g, i, cont=0;
    bool adj;
    no L[ordem+1];
    for (int i=0; i<ordem; i++){
        g = 0; Xs[i] = 0;
        for (int j=0; j<ordem; j++){
            if (G[i][j])g++;
        }
        aux = fim;
        while(aux >=0 && L[aux].g < g){
            L[aux+1] = L[aux];
            aux--;
        }
        L[aux+1].g = g;
        L[aux+1].v = i;
        fim++;
    }
    for (int w=0; w<ordem; w++){
        printf ("%d %d\n",L[w].v,L[w].g);
    }
    do{
        card=0;
        for (i=0; Xs[L[i].v] != 0; i++);
        Xs[L[i].v] = x;
        S[card++] = L[i].v;
        cont++;
        aux = i+1;
        while (aux <= fim){
            if(Xs[L[aux].v]==0){
                adj = false;
                for (int k=0; k<card; k++){
                    if (G[L[aux].v][S[k]] > 0)
                        adj = true;
                }
                if (!adj){
                    Xs[L[aux].v] = x;
                    S[card++] = L[aux].v;
                    cont++;
                }
            }
            aux++;
        }
        for (int w=0; w<ordem; w++) {
            printf("%d ",Xs[w]);
        }
        printf("\n");
        x++;
    } 
    while (cont < ordem);
}

int main(){
    int ordem = 7;
    int grafo[ordem][MAX] = {   {1, 0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 1, 0, 1, 0},
                                {1, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 1, 0, 0, 1},
                                {0, 0, 1, 0, 1, 1, 0},
                                {0, 1, 0, 0, 1, 1, 0},
                                {0, 0, 0, 1, 0, 0, 1}};

    prova(grafo,ordem);

    return 0;
}