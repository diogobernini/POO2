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



    return 0;
}
