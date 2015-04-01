#include <stdio.h>
#include <stdlib.h>
#include "main.h"

vetor *criaVetor(int N){
    vetor *v;
    v->tamanho = N;
    v->elementos = (double*) calloc(N,sizeof(double)*N);
    return v;
}
void liberaVetor(vetor *v){
    free(v->elementos);
    free(v);
}
void atribuiValor (vetor *v, int pos, double valor){
    v->elementos[pos]=valor;
}
void multiplicaVetor(vetor *v, double N){
    int i;
    for(i = 0; i<v->tamanho; i++){
        v->elementos[i] = v->elementos[i]*N;
    }
}
void quadradosVetor(vetor *v){
    int i;
    for(i = 0; i<v->tamanho; i++){
        v->elementos[i] = v->elementos[i]*v->elementos[i];
    }
}
void somaVetores(vetor *v1, vetor *v2, vetor *destino){
    int i;
    for(i = 0; i<v1->tamanho; i++){
        destino->elementos[i] = v1->elementos[i]+v2->elementos[i];
    }
}

void imprimeVetor(vetor *v1){
    int i;
    for(i = 0; i<v1->tamanho; i++){
        printf("Posicao %d: %.0f\n",i,v1->elementos[i]);
    }
}

void TroqueVetor(vetor *v1, vetor *v2){
    int i;
    double temp;
    for(i = 0; i<v1->tamanho; i++){
        temp = v1->elementos[i];
        v1->elementos[i] = v2->elementos[i];
        v2->elementos[i] = temp;
    }
}
