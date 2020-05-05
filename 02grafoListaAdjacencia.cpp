#include <bits/stdc++.h>

struct no{
    int vertice;
    no * proximo;
};

typedef no * noptr;

bool kregular (noptr grafo[], int ordem, int k){
    int grau; noptr atual;
    for(int i=0; i<ordem; i++){
        grau = 0;
        atual = grafo[i];
        while(atual != NULL){
            grau++;
            atual = atual->proximo;
        }
        if(grau != k) return false;
    }
    return true;
}