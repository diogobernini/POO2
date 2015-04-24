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
    FILE *fp;
      if((fp=fopen("tempo_ex.txt", "wb"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
      }
    int i,j;
    fprintf(fp,"VectorSize,ElapsedTime\n");
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
    fprintf(fp,"%d,%fs\n",i,diff/1000);
    printf("\n%d",i);
    }
    return 0;
}
