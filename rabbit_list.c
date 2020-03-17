/**
 * \file rabbit_list.c
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour stocker des lapins dans une liste
 * \version 0.1 
 * \date 16 mars 2020
 **/

#include "rabbit_list.h"


/* --------------------------------------------------------------------------*/
/*  list_rabbit_t new_list(void)                                             */
/** créer une liste vide
 *
 * @return NULL
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t new_list(void)
{
    return NULL;
}


/* --------------------------------------------------------------------------*/
/*  rabbit_t head(list_rabbit_t list_rabbit)                                 */
/** permet d'obtenir le premier élement de la liste
 *
 * @param  liste_rabbit liste de lapins
 * @return le premier lapin de la liste
 **/
/*---------------------------------------------------------------------------*/
rabbit_t head(list_rabbit_t list_rabbit)
{
    if(list_rabbit == NULL) {
        printf("op interdite\n");
        exit(1);
    }
    return list_rabbit->rabbit;
}

/* --------------------------------------------------------------------------*/
/*  Boolean empty(list_rabbit_t list_rabbit)                                 */
/** permet de savoir si la liste est vide
 *
 * @param  liste_rabbit liste de lapins
 * @return true si la liste est vide, false sinon
 **/
/*---------------------------------------------------------------------------*/
Boolean empty(list_rabbit_t list_rabbit)
{
    if(list_rabbit == NULL)
        return true;
    return false;
}

/* --------------------------------------------------------------------------*/
/*  list_rabbit_t add_head(list_rabbit_t list_rabbit, rabbit_t rabbit)       */
/** ajoute un lapin dans la liste
 *
 * @param  liste_rabbit liste de lapins
 * @param  rabbit lapin à ajouter à la liste
 * 
 * @return la liste avec le lapin ajouté
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t add_head(list_rabbit_t list_rabbit, rabbit_t rabbit)
{
    link_t * link;
    link = (link_t *)malloc(sizeof(link_t));
    if(link == NULL) {
        printf("pb malloc\n");
        exit(1);
    }
    link->rabbit = rabbit;
    link->next   = list_rabbit;
    return link;
}

/* --------------------------------------------------------------------------*/
/*  list_rabbit_t delete_head(list_rabbit_t list_rabbit)                     */
/** supprime le premier lapin de la liste
 *
 * @param  liste_rabbit liste de lapins
 * 
 * @return la liste avec le lapin supprimé
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t delete_head(list_rabbit_t list_rabbit)
{
    link_t * link;
    if(empty(list_rabbit)) {
        printf("forbidden operation\n");
        exit(1);
    }
    link        = list_rabbit;
    list_rabbit = list_rabbit->next;
    free(link);
    return list_rabbit;
}


/* --------------------------------------------------------------------------*/
/*  list_rabbit_t delete_dead(list_rabbit_t list_rabbit)                     */
/** supprime tout les lapins morts de la liste
 *
 * @param  liste_rabbit liste de lapins
 * 
 * @return la liste avec les lapins morts supprimés
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t delete_dead(list_rabbit_t list_rabbit)
{
    list_rabbit_t tmp, previous;

    if(empty(list_rabbit)) // si la liste est NULL on s'arrete tout de suite
        return list_rabbit;

    previous = list_rabbit;
    while(!empty(previous) && !previous->rabbit.alive) // Verifie la tete de
                                                       // liste, cas particulier
    {
        list_rabbit = previous->next;
        free(previous);
        previous = list_rabbit;
    }

    if(!empty(previous))
        tmp =
            previous->next; // le cas n est gere on se place donc sur le cas n+1
    else
        tmp = NULL;

    while(!empty(tmp)) // On boucle est on supprime si on trouve l'element
    {
        // supprime les morts à la suite les uns des autres
        while(!empty(tmp) && !tmp->rabbit.alive) {
            previous->next = tmp->next;
            free(tmp);
            tmp = previous->next;
        }

        previous = tmp;
        if(!empty(tmp))
            tmp = tmp->next;
    }
    return list_rabbit;
}


/* --------------------------------------------------------------------------*/
/*  void display_rabbit(rabbit_t rabbit)                                     */
/** affiche les informations d'un lapin
 *
 * @param rabbit un lapins
 * 
 **/
/*---------------------------------------------------------------------------*/
void display_rabbit(rabbit_t rabbit)
{
    printf("nb month : %d\tsexe : %d\n", rabbit.nb_years, rabbit.sexe);
}

/* --------------------------------------------------------------------------*/
/*  void display_rabbit_all(list_rabbit_t list_rabbit)                       */
/** affiche les informations de tous les lapins de la liste
 *
 * @param list_rabbit liste de lapins
 * 
 **/
/*---------------------------------------------------------------------------*/
void display_rabbit_all(list_rabbit_t list_rabbit)
{
    while(!empty(list_rabbit)) {
        display_rabbit(list_rabbit->rabbit);
        list_rabbit = list_rabbit->next;
    }
}

/* --------------------------------------------------------------------------*/
/*  void display_death(list_rabbit_t list_rabbit)                            */
/** affiche la valeur de la variable bouléene alive (pour debug)
 *
 * @param list_rabbit liste de lapins
 * 
 **/
/*---------------------------------------------------------------------------*/
void display_death(list_rabbit_t list_rabbit)
{
    int i = 1;
    while(!empty(list_rabbit)) {
        if(list_rabbit->rabbit.alive) {
            printf("rabbit %d : alive\n", i);
        }
        else {
            printf("rabbit %d : dead\n", i);
        }

        list_rabbit = list_rabbit->next;
        i++;
    }
}


/* --------------------------------------------------------------------------*/
/*  int size_list(list_rabbit_t list_rabbit)                                 */
/** compte le nombre d'éléments de la liste
 *
 * @param  liste_rabbit liste de lapins
 * 
 * @return le nombre d'éléments de la liste
 **/
/*---------------------------------------------------------------------------*/
int size_list(list_rabbit_t list_rabbit)
{
    list_rabbit_t tmp = list_rabbit;
    int           cpt = 0;
    while(tmp != NULL) {
        cpt++;
        tmp = tmp->next;
    }
    return cpt;
}