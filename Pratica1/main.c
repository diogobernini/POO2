// Grupo: Ada Lovelace

// Integrante #1: Diogo Bernini Milagres

// Integrante #2: João Vitor Almeida

// Integrante #3: Alexandre Vieira

// Prática: 01

// Exercício: 1
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void preenche(vetor *v){
    int i;
    for(i=0;i<v->tamanho;i++)
        atribuiValor(v,i,i+1);
}

int main()
{
    vetor *v = criaVetor(5);
    vetor *v2 = criaVetor(5);
    vetor *v3 = criaVetor(5);

    preenche(v);
    preenche(v2);

    multiplicaVetor(v,3);
    quadradosVetor(v2);
    somaVetores(v,v2,v3);
    TroqueVetor(v,v3);

    imprimeVetor(v);
    imprimeVetor(v2);
    imprimeVetor(v3);

    liberaVetor(v);
    liberaVetor(v2);
    return 0;
}
