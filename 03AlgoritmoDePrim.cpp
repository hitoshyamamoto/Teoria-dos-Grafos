#include <bits/stdc++.h> 
using namespace std; 

#define quantVertice 8

void algoritmoPrim(int grafo[quantVertice][quantVertice]){
    int listaArvGerMin[quantVertice];
    int listaPesosMin[quantVertice];   
    bool listaVert[quantVertice];
   
    for(int i = 0; i < quantVertice; i++)  
        listaPesosMin[i] = INT_MAX, listaVert[i] = false;  
  
    listaPesosMin[0] = 0;  
    listaArvGerMin[0] = -1;
  
    for(int count = 0; count < quantVertice - 1; count++){  
        int menorPeso = encontrarMenorPeso(listaPesosMin, listaVert); 
  
        listaVert[menorPeso] = true;  
   
        for(int v = 0; v < quantVertice; v++)  
            if (grafo[menorPeso][v] && listaVert[v] == false && grafo[menorPeso][v] < listaPesosMin[v])  
                listaArvGerMin[v] = menorPeso, listaPesosMin[v] = grafo[menorPeso][v];  
    }  

    imprimirPrim(listaArvGerMin, grafo);  
} 
  
int encontrarMenorPeso(int listaPesosMin[], bool listaVert[]){
    int minimos = INT_MAX, indiceMinimos;
  
    for(int vertices = 0; vertices < quantVertice; vertices++)  
        if(listaVert[vertices] == false && listaPesosMin[vertices] < minimos){
            minimos = listaPesosMin[vertices];
            indiceMinimos = vertices;
        }  
  
    return indiceMinimos;  
}  

void imprimirPrim(int listaArvGerMin[], int grafo[quantVertice][quantVertice]){  
    printf("Vertice \tPeso\n");
    for(int i = 1; i < quantVertice; i++)
        printf("%d  -  %d \t  %d \n", listaArvGerMin[i], i, grafo[i][listaArvGerMin[i]]);
} 

int main(){  
    int grafo[quantVertice][quantVertice]= {{ 0, 2, 0, 8, 8, 2, 1, 0 },  
                                            { 2, 0, 1, 0, 7, 0, 8, 1 },  
                                            { 0, 1, 0, 1, 0, 1, 7, 8 },  
                                            { 8, 0, 1, 0, 6, 8, 0, 0 },  
                                            { 8, 7, 0, 6, 0, 0, 6, 1 },
                                            { 2, 0, 1, 8, 0, 0, 2, 8 },
                                            { 1, 8, 7, 0, 6, 2, 0, 7 },
                                            { 0, 1, 8, 0, 1, 8, 7, 0 }};  
    algoritmoPrim(grafo);  
  
    return 0;  
}  