// Grupo: Alan Turing

// Integrante #1: Alexandre Vieira dos Santos

// Integrante #2: Diogo Bernini Milagres

// Integrante #3: João Vitor Almeida Alves

// Prática: 02

// Exercício: -
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double calcula(clock_t fim, clock_t ini){
    return ((double) (fim - ini) / CLOCKS_PER_SEC);
}

int fibonacci1(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return (fibonacci1(n-1) + fibonacci1(n-2));
}

int fibonacci2(int n){
    int i = 2;
    int v[50];

    v[0] = 0;
    v[1] = 1;

    while(i <= n){
        v[i] = v[i-1] + v[i-2];
        i++;
    }

    return v[n];
}

int fibonacci3(int n){
    double a1, a2, r;

    a1 = pow((1 + (sqrt(5))) / 2, n);
    a2 = pow((1 - (sqrt(5))) / 2, n);
    r = (a1 - a2) / (sqrt(5));
    return (int)r;
}


int main(){
    int fb, n;
    clock_t t1, t2;
    double total;

    printf("Digite o N: ");
    scanf("%d", &n);

    t1 = clock();
    fb = fibonacci1(n);
    t2 = clock();
    total = calcula(t2, t1);
    printf("\nMetodo #1 Fibonacci %d = %d\nDuracao de %.3lf seg.\n\n", n, fb, total);

    t1 = clock();
    fb = fibonacci2(n);
    t2 = clock();
    total = calcula(t2, t1);
    printf("\nMetodo #2 Fibonacci %d = %d\nDuracao de %.3lf seg.\n\n", n, fb, total);

    t1 = clock();
    fb = fibonacci3(n);
    t2 = clock();
    total = calcula(t2, t1);
    printf("\nMetodo #3 Fibonacci %d = %d\nDuracao de %.3lf seg.\n\n", n, fb, total);

// Pode se concluir que há várias maneiras diferentes de implementar um algoritmo, e que, se utilizando da análise de algoritmo é possível otimizá-lo da melhor maneira possível.
// Quando o algoritmo é iterativo não há diferença, porém quando ele é recursivo ele utiliza-se de mais memória à cada passo recursivo.

    return 0;
}
