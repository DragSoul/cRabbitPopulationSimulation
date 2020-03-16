#include <stdio.h>
#include "fibo.h"
#include "rabbit.h"
#include "rabbitTreeStatus.h"

void question1()
{
    int n1 = fibo_recurente(15);
    int n2 = fibo_recursif(15);
    int n3 = fibo_explicite(15);
    printf("%d\t%d\t%d\n", n1, n2, n3);
}


/* ---------------------------------------------------------- */
/*                         compute_S                          */

/* Description : calcul l'estimateur sans biais de la variance*/

/* En entrée :  tab : tableau
                n : taille du tableau
                moyenne : moyenne du tableau                  */

/* En sortie : S                                              */
/* -----------------------------------------------------------*/
double compute_S(unsigned long tab[], int n, double moyenne){
    double  somme = 0;

    for(int i = 0; i < n; i++){
        somme += (tab[i] - moyenne)*(tab[i] - moyenne);
    }

    return somme/(n-1);
}

double calcul_moyenne_long(unsigned long tab[], int n){
    unsigned long  moyenne = 0;

    for(int i = 0; i < n; i++){
        moyenne += tab[i];
    }

    return moyenne/n;
}

void intervalle_de_confiance(unsigned long tab[], int nbExp){
    double moyenne, le_S, le_R; 
    int borne_inf, borne_sup;

    moyenne = calcul_moyenne_long(tab, nbExp);
    le_S = compute_S(tab, nbExp, moyenne);
    le_R = 1.98*sqrt(le_S/nbExp);
    borne_inf = (int)round(moyenne - le_R);
    borne_sup = (int)round(moyenne + le_R);

    printf("intervalle de confiance à 95\% = [%d, %d]\n", borne_inf, borne_sup);
}



int main()
{
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    //question1();
    //realistic_simulation2();

    int nbExp = 10;
    unsigned long tab_exp[10] = {0};
    double tabProbaLitter[5] = {0.1, 0.2, 0.4, 0.2, 0.1};
    double tabProbaBabys[4] = {0.25,0.25,0.25,0.25};
    configSimu_t config;
    config.maxRabbitYear = 15;
    config.ageDisminish = 10;
    config.littleRabbitSurvRate = 0.35;
    config.maxBabyPerLitter = 6;
    config.maxLitterPerYear = 8;
    config.maxYear = 10;
    config.minBabyPerLitter = 3;
    config.minLitterPerYear = 4;
    config.probaLittersBabys = tabProbaBabys;
    config.probaLittersYear = tabProbaLitter;
    config.rabbitSurvRate = 0.6;
    config.rateDisminish = 0.1;
    config.initPredator = 1;

    for(int i = 0; i < nbExp; i++)
    {
        tab_exp[i] = realistic_simulation_TS(config);
        printf("\n");
    }
    intervalle_de_confiance(tab_exp, nbExp);
    return 0;
}