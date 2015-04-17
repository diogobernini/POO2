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
    for(i=0;i<tamanho;i++)
        vetor[i]=rand() % (tamanho*5);
}

void imprimeVetor(int *vetor, int tamanho)
{
    int i;
    for(i=0;i<tamanho;i++)
        printf("%d, ", vetor[i]);
}

void alocaOrdenaDesaloca(tamanhoVetor)
{
    time_t tempoAntes, tempoDepois;
    double duracao;
    // Aloca o vetor
    int *vetor = (int) malloc(tamanhoVetor*sizeof(int));
    // Chama a função que preenche com números aleatórios
    preencheVetor(vetor,tamanhoVetor);
    // Ordena de acordo com a função comparadora
    time(&tempoAntes);
    qsort (vetor, tamanhoVetor, sizeof(int), comparador);
    time(&tempoDepois);
    // Imprime o vetor final
    //imprimeVetor(vetor,tamanhoVetor);
    duracao = difftime(tempoDepois,tempoAntes);
    printf("\n%d valores, processo executado em %.f segundos.", tamanhoVetor, duracao);
}

int main()
{
    int i;
    for(i=1;i<100000;i++)
        alocaOrdenaDesaloca(i);
    return 0;
}
