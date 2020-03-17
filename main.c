/**
 * \file main.c
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour réaliser une simulation stocastique de l'évolution
 d'une population de lapin
 * \version 0.1 \date 16 mars 2020
 **/

#include "fibo.h"
#include "rabbit.h"
#include "rabbitTreeStatus.h"
#include <stdio.h>

/* --------------------------------------------------------------------------*/
/*  void question1()                                                         */
/** calcul le 11 eme élément de la suite de fibonacci avec trois méthodes
différentes
 *
 * @return void
 **/
/*---------------------------------------------------------------------------*/
void question1()
{
    unsigned long n1 = fibo_recurence(11);
    unsigned long n2 = fibo_recursif(11);
    unsigned long n3 = fibo_explicite(11);
    printf("formule de récurrence : %lu\nformule récursive : %lu\nformule "
           "explicite : %lu\n",
           n1, n2, n3);
}

/* --------------------------------------------------------------------------*/
/*  double compute_S(unsigned long tab[], int n, double moyenne)             */
/** calcul l'estimateur sans biais de la variance
 *
 * @param  tab tableau
 * @param  n taille du tableau
 * @param  moyenne moyenne du tableau
 * @return S
 **/
/*---------------------------------------------------------------------------*/
double compute_S(unsigned long tab[], int n, double moyenne)
{
    double somme = 0;

    for(int i = 0; i < n; i++) {
        somme += (tab[i] - moyenne) * (tab[i] - moyenne);
    }

    return somme / (n - 1);
}

/* --------------------------------------------------------------------------*/
/*  double calcul_moyenne_long(unsigned long tab[], int n)                   */
/** fonction pour calculer la moyenne d'un tableau de unsigned long
 *
 * @param  tab tableau
 * @param  n taille du tableau
 * @return moyenne du tableau
 **/
/*---------------------------------------------------------------------------*/
double calcul_moyenne_long(unsigned long tab[], int n)
{
    unsigned long moyenne = 0;

    for(int i = 0; i < n; i++) {
        moyenne += tab[i];
    }

    return moyenne / n;
}

/* --------------------------------------------------------------------------*/
/*  void intervalle_de_confiance(unsigned long tab[], int nbExp)             */
/** fonction pour calculer et afficher l'intervalle de confiance d'un tableau 
de unsigned long
 *
 * @param  tab tableau
 * @param  nbExp taille du tableau / nombre d'espériences
 * @return void
 **/
/*---------------------------------------------------------------------------*/
void intervalle_de_confiance(unsigned long tab[], int nbExp)
{
    double moyenne, le_S, le_R;
    int    borne_inf, borne_sup;

    moyenne   = calcul_moyenne_long(tab, nbExp);
    le_S      = compute_S(tab, nbExp, moyenne);
    le_R      = 1.98 * sqrt(le_S / nbExp);
    borne_inf = (int)round(moyenne - le_R);
    borne_sup = (int)round(moyenne + le_R);

    printf("intervalle de confiance à 95\% = [%d, %d]\n", borne_inf, borne_sup);
}

/* --------------------------------------------------------------------------*/
/*  void question2_list()                                                    */
/** fonction pour réaliser une simulation d'évolution de population de lapin 
avec une structure list
 *
 * @return void
 **/
/*---------------------------------------------------------------------------*/
void question2_list()
{
    realistic_simulation();
}

/* --------------------------------------------------------------------------*/
/*  void question2_TS()                                                      */
/** fonction pour réaliser une simulation d'évolution de population de lapin 
avec une structure d'arbre d'états
 *
 * @return void
 **/
/*---------------------------------------------------------------------------*/
void question2_TS()
{
    int           nbExp             = 10;
    unsigned long tab_exp[10]       = { 0 };
    double        tabProbaLitter[5] = { 0.1, 0.2, 0.4, 0.2, 0.1 };
    double        tabProbaBabys[4]  = { 0.25, 0.25, 0.25, 0.25 };

    configSimu_t config;
    config.maxRabbitYear        = 15;
    config.ageDisminish         = 10;
    config.littleRabbitSurvRate = 0.35;
    config.maxBabyPerLitter     = 6;
    config.maxLitterPerYear     = 8;
    config.maxYear              = 10;
    config.minBabyPerLitter     = 3;
    config.minLitterPerYear     = 4;
    config.probaLittersBabys    = tabProbaBabys;
    config.probaLittersYear     = tabProbaLitter;
    config.rabbitSurvRate       = 0.6;
    config.rateDisminish        = 0.1;
    config.initPredator         = 1;

    for(int i = 0; i < nbExp; i++) {
        printf("exp %d\n", i);
        tab_exp[i] = realistic_simulation_TS(config);
    }
    intervalle_de_confiance(tab_exp, nbExp);
}

/* --------------------------------------------------------------------------*/
/*  int main()                                                               */
/** point d'entré du programe, ici elle appelle question2_TS et initialise le 
générateur de nombre pseudo-aléatoire
 *
 * @return void
 **/
/*---------------------------------------------------------------------------*/
int main()
{
    unsigned long init[4] = { 0x123, 0x234, 0x345, 0x456 }, length = 4;
    init_by_array(init, length);

    // question1();
    // realistic_simulation2();
    // question2_list();
    question2_TS();
    return 0;
}