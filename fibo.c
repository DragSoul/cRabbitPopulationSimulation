#include "fibo.h"


//suite de fibonacci implémentée récursivement
int fibo_recursif(int n)
{
    if(n < 2)
    {
        return n;
    }
    return fibo_recursif(n-1)+fibo_recursif(n-2);
}


//suite de fibonacci implémentée sous sa forme récurrente
int fibo_recurente(int n)
{
    int Un, Un_1 = 1, Un_2 = 0;
    if(n == 0) return Un_2;
    if(n == 1) return Un_1;
    for(int i = 1; i < n; i++)
    {
        Un = Un_1 + Un_2;
        Un_2 = Un_1;
        Un_1 = Un;
    }
    return Un;
}


//suite de fibonacci implémentée sous sa forme explicite
int fibo_explicite(int n)
{
    double phi, phi_prime;
    phi = (1+sqrt(5))/2;
    phi_prime = (1-sqrt(5))/2;

    return (1/sqrt(5)) * (pow(phi, n) - pow(phi_prime, n));
}

 