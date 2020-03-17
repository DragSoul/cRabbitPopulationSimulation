/**
 * \file rabbit_list.h
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour stocker des lapins dans une liste
 * \version 0.1
 * \date 16 mars 2020
 **/
#ifndef RABBIT_LIST_H
#define RABBIT_LIST_H

#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------------------*/
/**
 * \enum sexe_t
 * \brief structure pour définir le sexe d'un lapin
 */
/*---------------------------------------------------------------------------*/
typedef enum { male, female } sexe_t;

/*---------------------------------------------------------------------------*/
/**
 * \enum Boolean
 * \brief structure pour définir un type boolean
 */
/*---------------------------------------------------------------------------*/
typedef enum { false, true } Boolean;

/*---------------------------------------------------------------------------*/
/**
 * \struct rabbit_t
 * \brief structure qui définit un lapin
 */
/*---------------------------------------------------------------------------*/
typedef struct {
    sexe_t  sexe; /*!< sexe du lapin                                         */
    int     nb_years; /*!< age du lapin                                      */
    Boolean alive; /*!< variable qui définit si le lapin est vivant          */
} rabbit_t;

/*---------------------------------------------------------------------------*/
/**
 * \struct list_rabbit_t
 * \brief structure qui définit une liste chainée de lapins
 */
/**
 * \struct link_t
 * \brief structure qui définit une cellule de liste chainée de lapins
 */
/*---------------------------------------------------------------------------*/
typedef struct link {
    rabbit_t      rabbit; /*!< valeur de la cellule, ici un lapin            */
    struct link * next; /*!< pointeur sur la cellule suivante                 */
} link_t, *list_rabbit_t;

/* --------------------------------------------------------------------------*/
/*  list_rabbit_t new_list(void)                                             */
/** créer une liste vide
 *
 * @return NULL
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t new_list(void);

/* --------------------------------------------------------------------------*/
/*  rabbit_t head(list_rabbit_t list_rabbit)                                 */
/** permet d'obtenir le premier élement de la liste
 *
 * @param  list_rabbit liste de lapins
 * @return le premier lapin de la liste
 **/
/*---------------------------------------------------------------------------*/
rabbit_t head(list_rabbit_t list_rabbit);

/* --------------------------------------------------------------------------*/
/*  Boolean empty(list_rabbit_t list_rabbit)                                 */
/** permet de savoir si la liste est vide
 *
 * @param  list_rabbit liste de lapins
 * @return true si la liste est vide, false sinon
 **/
/*---------------------------------------------------------------------------*/
Boolean empty(list_rabbit_t list_rabbit);

/* --------------------------------------------------------------------------*/
/*  list_rabbit_t add_head(list_rabbit_t list_rabbit, rabbit_t rabbit)       */
/** ajoute un lapin dans la liste
 *
 * @param  list_rabbit liste de lapins
 * @param  rabbit lapin à ajouter à la liste
 *
 * @return la liste avec le lapin ajouté
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t add_head(list_rabbit_t list_rabbit, rabbit_t rabbit);

/* --------------------------------------------------------------------------*/
/*  list_rabbit_t delete_head(list_rabbit_t list_rabbit)                     */
/** supprime le premier lapin de la liste
 *
 * @param  list_rabbit liste de lapins
 *
 * @return la liste avec le lapin supprimé
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t delete_head(list_rabbit_t list_rabbit);

/* --------------------------------------------------------------------------*/
/*  list_rabbit_t delete_dead(list_rabbit_t list_rabbit)                     */
/** supprime tout les lapins morts de la liste
 *
 * @param  list_rabbit liste de lapins
 *
 * @return la liste avec les lapins morts supprimés
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t delete_dead(list_rabbit_t list_rabbit);

/* --------------------------------------------------------------------------*/
/*  void display_rabbit(rabbit_t rabbit)                                     */
/** affiche les informations d'un lapin
 *
 * @param rabbit un lapins
 *
 **/
/*---------------------------------------------------------------------------*/
void display_rabbit(rabbit_t rabbit);

/* --------------------------------------------------------------------------*/
/*  void display_rabbit_all(list_rabbit_t list_rabbit)                       */
/** affiche les informations de tous les lapins de la liste
 *
 * @param list_rabbit liste de lapins
 *
 **/
/*---------------------------------------------------------------------------*/
void display_rabbit_all(list_rabbit_t list_rabbit);

/* --------------------------------------------------------------------------*/
/*  void display_death(list_rabbit_t list_rabbit)                            */
/** affiche la valeur de la variable bouléene alive (pour debug)
 *
 * @param list_rabbit liste de lapins
 *
 **/
/*---------------------------------------------------------------------------*/
void display_death(list_rabbit_t list_rabbit);

/* --------------------------------------------------------------------------*/
/*  int size_list(list_rabbit_t list_rabbit)                                 */
/** compte le nombre d'éléments de la liste
 *
 * @param  list_rabbit liste de lapins
 *
 * @return le nombre d'éléments de la liste
 **/
/*---------------------------------------------------------------------------*/
int size_list(list_rabbit_t list_rabbit);

#endif
