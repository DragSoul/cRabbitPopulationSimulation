/**
 * \file rabbit.h
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour gérer les lapins ainsi que la simulation de
 * l'évolution de la population de lapin dans le temps
 * \version 0.1
 * \date 16 mars 2020
 **/

#ifndef RABBIT_H
#define RABBIT_H

#include "fibo.h"
#include "mt19937ar.h"
#include "rabbit_list.h"
#include <stdio.h>
#include <stdlib.h>

/* --------------------------------------------------------------------------*/
/*  rabbit_t new_rabbit(int years)                                           */
/** créer un lapin de sexe aléatoire
 *
 * @param years age du lapin
 *
 * @return un lapin
 **/
/*---------------------------------------------------------------------------*/
rabbit_t new_rabbit(int years);

/* --------------------------------------------------------------------------*/
/*  rabbit_t new_rabbit2(int years, sexe_t sexe)                             */
/** créer un lapin de sexe défini
 *
 * @param years age du lapin
 * @param sexe sexe du lapin
 *
 * @return un lapin
 **/
/*---------------------------------------------------------------------------*/
rabbit_t new_rabbit2(int years, sexe_t sexe);

/* --------------------------------------------------------------------------*/
/*  sexe_t is_male(rabbit_t rabbit)                                          */
/** permet de savoir si le lapin est un mâle
 *
 * @param rabbit un lapin
 *
 * @return true si le lapin est un mâle
 **/
/*---------------------------------------------------------------------------*/
sexe_t is_male(rabbit_t rabbit);

/* --------------------------------------------------------------------------*/
/*  sexe_t is_female(rabbit_t rabbit)                                        */
/** permet de savoir si le lapin est une femelle
 *
 * @param rabbit un lapin
 *
 * @return true si le lapin est une femelle
 **/
/*---------------------------------------------------------------------------*/
sexe_t is_female(rabbit_t rabbit);

/* --------------------------------------------------------------------------*/
/*  Boolean give_birth(rabbit_t rabbit)                                      */
/** permet de savoir si le lapin donne naissance à une portée
 *
 * @param rabbit un lapin
 *
 * @return true si le lapin donne naissance
 **/
/*---------------------------------------------------------------------------*/
Boolean give_birth(rabbit_t rabbit);

/* --------------------------------------------------------------------------*/
/*  Boolean survive(rabbit_t rabbit)                                         */
/** permet de savoir si le lapin survit jusqu'à l'année suivante
 *
 * @param rabbit un lapin
 *
 * @return true si le lapin survit
 **/
/*---------------------------------------------------------------------------*/
Boolean survive(rabbit_t rabbit);

/* --------------------------------------------------------------------------*/
/*  Boolean is_alive(rabbit_t rabbit)                                        */
/** retourne la variable bouléene alive du lapin
 *
 * @param rabbit un lapin
 *
 * @return true si le lapin est en vie
 **/
/*---------------------------------------------------------------------------*/
Boolean is_alive(rabbit_t rabbit);

/* --------------------------------------------------------------------------*/
/*  list_rabbit_t survive_all(list_rabbit_t list_rabbit)                     */
/** change la valeur du bouléen alive pour tous les lapins de la liste
 *
 * @param list_rabbit une liste de lapin
 *
 * @return la nouvelle liste de lapins après modification du bouléen
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t survive_all(list_rabbit_t list_rabbit);

/* --------------------------------------------------------------------------*/
/*  void realistic_simulation()                                              */
/** fonction pour réaliser une simulation d'évolution de population de lapin
 sur plusieurs années
 **/
/*---------------------------------------------------------------------------*/
void realistic_simulation();

#endif