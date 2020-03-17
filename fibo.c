/**
 * \file fibo.c
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour calculer les termes de la suite de Fibonacci.
 * \version 0.1
 * \date 16 mars 2020
 **/

#include "fibo.h"

/* --------------------------------------------------------------------------*/
/*  unsigned long fibo_recursif(int n)                                       */
/** fonction pour obtenir le n-ième terme de la suite de Fibonacci
 * implémentée récursivement
 *
 * @param  n indice du terme voulu
 * @return le terme à la n-ième place dans la suite
 **/
/*---------------------------------------------------------------------------*/
unsigned long fibo_recursif(int n)
{
    if(n < 2) {
        return n;
    }
    return fibo_recursif(n - 1) + fibo_recursif(n - 2);
}

/* --------------------------------------------------------------------------*/
/*  unsigned long fibo_recurence(int n)                                      */
/** fonction pour obtenir le n-ième terme de la suite de Fibonacci
 * implémentée à l'aide de la formule de récurrence
 *
 * @param  n indice du terme voulu
 * @return le terme à la n-ième place dans la suite
 **/
/*---------------------------------------------------------------------------*/
unsigned long fibo_recurence(int n)
{
    int Un, Un_1 = 1, Un_2 = 0;
    if(n == 0)
        return Un_2;
    if(n == 1)
        return Un_1;
    for(int i = 1; i < n; i++) {
        Un   = Un_1 + Un_2;
        Un_2 = Un_1;
        Un_1 = Un;
    }
    return Un;
}

/* --------------------------------------------------------------------------*/
/*  unsigned long fibo_explicite(int n)                                      */
/** fonction pour obtenir le n-ième terme de la suite de Fibonacci
 * implémentée à l'aide de la formule explicite
 *
 * @param  n indice du terme voulu
 * @return le terme à la n-ième place dans la suite
 **/
/*---------------------------------------------------------------------------*/
unsigned long fibo_explicite(int n)
{
    double phi, phi_prime;
    phi       = (1 + sqrt(5)) / 2;
    phi_prime = (1 - sqrt(5)) / 2;

    return (1 / sqrt(5)) * (pow(phi, n) - pow(phi_prime, n));
}
