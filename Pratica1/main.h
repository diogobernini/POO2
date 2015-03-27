#include <stdio.h>
#include <stdlib.h>

typedef struct {
 int tamanho;
 double *elementos;
} vetor;

vetor *criaVetor(int N);
void liberaVetor(vetor *v);
void atribuiValor (vetor *v, int pos, double valor);
void multiplicaVetor(vetor *v, double N);
void quadradosVetor(vetor *v);
void somaVetores(vetor *v1, vetor *v2, vetor *destino);
void TroqueVetor(vetor *v1, vetor *v2);
