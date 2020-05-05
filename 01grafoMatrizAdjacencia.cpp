#include <bits/stdc++.h>
#define MAX_NOS 10

using namespace std;

bool kregular(int grafo[][MAX_NOS], int ordem, int k){
    int grau;
    for(int i=0; i<ordem; i++){
        grau = 0;
        for(int j=0; j<ordem; j++){
            if(grafo[i][j] == 1) grau++;
        }

        if(grau != k) return false;
    }

    return true;
}

int get(int Grafo[], int i, int j){
    if(i>=j){
        return Grafo[(i*(i+1)/2) + j];
    }
    else{
        return Grafo[(j*(j+1)/2) + i];
    }
}

void set(int Grafo[], int i, int j, int v){
    if(i>=j){
        Grafo[(i*(i+1)/2) + j];
    }
    else{
        Grafo[(j*(j+1)/2) + i];
    }
}

int main(){
    return 0;
}