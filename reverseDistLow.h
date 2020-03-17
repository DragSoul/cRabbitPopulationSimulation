/**
 * \file reverseDistLow.h
 * \author Aurelien DOUARD
 * \brief Programmes pour générer des nombre pseudo-aléatoire qui suivent une
 *probabilité donné \version 0.1 \date 16 février 2020
 **/

#ifndef RDL_H
#define RDL_H

#include "mt19937ar.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * \fn double * probaCalc(int tab[], int len)
 * \brief Fonction qui calcule la probabilité de chaque élément du tableau
 *
 * \param tab tableau remplit avec les evenements
 * \param len la taile du tableau
 * \return un tableau avec la probabilité de chaque élément
 */
double * probaCalc(int tab[], int len);

/**
 * \fn void discDist(double rand, int  tab[], double  cumulProba[], int
 * nbClass); \brief Fonction qui générer des nombre qui suivent une probabilité
 * donné à partir d'un nombre pseudo-aléatoire
 *
 * \param tab tableau remplit avec fréquences
 * \param nbClass nombre de classes différentes du dans le tableau
 * \param cumulProba tableau remplit avec la probabilité cumulé pour chaque
 * classes \param rand nombre pseudo-aléatoire
 */
void discDist(double rand, int tab[], double cumulProba[], int nbClass);

/**
 * \fn int * discDispLoop(double cumulProba[], int nbClass, int nbExp)
 * \brief Fonction qui générer des nombre qui suivent une probabilité pour x
 * tirage
 *
 * \param nbExp nombre de tirages
 * \param nbClass nombre de classes différentes du dans le tableau
 * \param cumulProba tableau remplit avec la probabilité cumulé pour chaque
 * classes \return tableau remplit avec fréquences
 */
int * discDispLoop(double cumulProba[], int nbClass, int nbExp);

/**
 * \fn double * calcCumulProba(double tabProb[], int len)
 * \brief Fonction qui calcule la probabilité cumulé de chaque élément du
 * tableau
 *
 * \param tabProb tableau remplit avec les probabilité
 * \param len la taile du tableau
 * \return un tableau avec la probabilité cumulé de chaque élément
 */
double * calcCumulProba(double tabProb[], int len);

/**
 * \fn int genRand_discDist(double rand, double  cumulProba[], int nbClass)
 * \brief Fonction qui génére un nombre qui suit une probabilité donné à partir
 * d'un nombre pseudo-aléatoire
 *
 * \param nbClass nombre de classes différentes du dans le tableau
 * \param cumulProba tableau remplit avec la probabilité cumulé pour chaque
 * classes \param rand nombre pseudo-aléatoire
 */
int genRand_discDist(double rand, double cumulProba[], int nbClass);

#endif