#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparador (const void *x, const void *y)
{
    return ( *(int*)x - *(int*)y );
}
void preencheVetor (int *vetor, int tamanho)
{
    srand (time(NULL));
    int i;
    for(i=0; i<tamanho; i++)
        vetor[i]=rand() % (tamanho*5);
}

void imprimeVetor(int *vetor, int tamanho)
{
    int i;
    for(i=0; i<tamanho; i++)
        printf("%d, ", vetor[i]);
}

void alocaOrdenaDesaloca(tamanhoVetor)
{
    int *vetor = (int) malloc(tamanhoVetor*sizeof(int));
    preencheVetor(vetor,tamanhoVetor);
    qsort (vetor, tamanhoVetor, sizeof(int), comparador);
    free(vetor);
}

int main()
{
    int i,j;
    clock_t t1, t2;
    for(i=1; i<10000; i++)
    {
    t1 = clock();
        for(j=0; j<1000; j++)
        {
            alocaOrdenaDesaloca(i);
            //printf("alocando pela %d,%d vez\n",i,j);
        }
    //printf("alocando pela %d vez\n",i);
    t2 = clock();
    float diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
    printf("\nVetor tamanho (%d): %fs",i,diff);
    }
    return 0;
}
