#include "rabbit_list.h"

// créer une nouvelle liste
list_rabbit_t new_list(void)
{
    return NULL;
}

// renvoie le premier lapin de la liste
rabbit_t head(list_rabbit_t list_rabbit)
{
    if(list_rabbit == NULL) {
        printf("op interdite\n");
        exit(1);
    }
    return list_rabbit->rabbit;
}

// renvoie true si la liste est vide
Boolean empty(list_rabbit_t list_rabbit)
{
    if(list_rabbit == NULL)
        return true;
    return false;
}

// ajoute un lapin en debut de liste
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

// supprime le premier lapin de la liste
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

    while(!empty(tmp)) // On Mouline est on supprime si on trouve l'element
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

// affiche le nombre d'elements d'une liste
int nb_element(list_rabbit_t list_rabbit)
{
    int cpt = 0;
    while(list_rabbit != NULL) {
        cpt         = cpt + 1;
        list_rabbit = list_rabbit->next;
    }
    return cpt;
}

// affiche l'age et le sexe du lapin
void display_rabbit(rabbit_t rabbit)
{
    printf("nb month : %d\tsexe : %d\n", rabbit.nb_years, rabbit.sexe);
}

// affiche l'age et le sexe de chaque lapin de la liste
void display_rabbit_all(list_rabbit_t list_rabbit)
{
    while(!empty(list_rabbit)) {
        display_rabbit(list_rabbit->rabbit);
        list_rabbit = list_rabbit->next;
    }
}

// affiche la liste des lapins avec le booleen 'alive'
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