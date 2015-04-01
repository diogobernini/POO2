#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibonacci3(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return (fibonacci3(n-1) + fibonacci3(n-2));
}



int fibonacci2(int n){
    double a1, a2, r;

    a1 = pow((1 + (sqrt(5))) / 2, n);
    a2 = pow((1 - (sqrt(5))) / 2, n);
    r = (a1 - a2) / (sqrt(5));
    return (int)r;
}


int fibonacci1(int n){
    int i = 2;
    int v[50];

    v[0] = 0;
    v[1] = 1;

    while(i <= n){
        v[i++] = v[i-1] + v[i-2];
    }

    return v[n];
}


int main(){
    int fb1, fb2, fb3, n;

    printf("Digite o N: ");
    scanf("%d", &n);

    fb1 = fibonacci1(n);
    printf("\nMetdo #1 Fibonacci %d = %d\n\n", n, fb1);
    fb2 = fibonacci2(n);
    printf("Metdo #2 Fibonacci %d = %d\n\n", n, fb2);
    fb3 = fibonacci3(n);
    printf("Metdo #3 Fibonacci %d = %d\n\n", n, fb3);
    return 0;
}
