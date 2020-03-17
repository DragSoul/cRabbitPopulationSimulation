/**
 * \file reverseDistLow.c
 * \author Aurelien DOUARD
 * \brief Programmes pour générer des nombre pseudo-aléatoire qui suivent une
 *probabilité donné 
 * \version 0.1 
 * \date 16 février 2020
 **/

#include "reverseDistLow.h"

double * probaCalc(int tab[], int len)
{
    double * tabRes = NULL;
    int      somme  = 0;
    tabRes          = calloc(sizeof(double), len);
    for(int i = 0; i < len; i++) {
        somme += tab[i];
    }
    for(int i = 0; i < len; i++) {
        tabRes[i] = (tab[i] * 1.) / (somme * 1.);
    }
    return tabRes;
}

void discDist(double rand, int tab[], double cumulProba[], int nbClass)
{
    for(int i = 0; i < nbClass; i++) {
        if(rand < cumulProba[i]) {
            tab[i] = tab[i] + 1;
            return;
        }
    }
}

int genRand_discDist(double rand, double cumulProba[], int nbClass)
{
    for(int i = 0; i < nbClass; i++) {
        if(rand < cumulProba[i]) {
            return i;
        }
    }
}

int * discDispLoop(double cumulProba[], int nbClass, int nbExp)
{
    int * tab = NULL;
    tab       = calloc(sizeof(int), nbClass);
    for(int i = 0; i < nbExp; i++) {
        discDist(genrand_real2(), tab, cumulProba, 3);
    }
    return tab;
}

double * calcCumulProba(double tabProb[], int len)
{
    double * tabCumuProb = NULL;
    tabCumuProb          = calloc(sizeof(double), len);
    tabCumuProb[0]       = tabProb[0];

    for(int i = 1; i < len; i++) {
        tabCumuProb[i] = tabCumuProb[i - 1] + tabProb[i];
    }
    return tabCumuProb;
}