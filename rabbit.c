/**
 * \file rabbit.c
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour gérer les lapins ainsi que la simulation de
 * l'évolution de la population de lapin dans le temps
 * \version 0.1 
 * \date 16 mars 2020
 **/

#include "rabbit.h"

int nb_loop = 1;

/* --------------------------------------------------------------------------*/
/*  rabbit_t new_rabbit(int years)                                           */
/** créer un lapin de sexe aléatoire
 *
 * @param years age du lapin
 * 
 * @return un lapin
 **/
/*---------------------------------------------------------------------------*/
rabbit_t new_rabbit(int years)
{
    rabbit_t rabbit;
    rabbit.nb_years = years;
    rabbit.alive    = true;
    rabbit.sexe     = round(genrand_real2());
    return rabbit;
}


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
rabbit_t new_rabbit2(int years, sexe_t sexe)
{
    rabbit_t rabbit;
    rabbit.nb_years = years;
    rabbit.alive    = true;
    rabbit.sexe     = sexe;
    return rabbit;
}

/* --------------------------------------------------------------------------*/
/*  sexe_t is_male(rabbit_t rabbit)                                          */
/** permet de savoir si le lapin est un mâle
 *
 * @param rabbit un lapin
 * 
 * @return true si le lapin est un mâle
 **/
/*---------------------------------------------------------------------------*/
sexe_t is_male(rabbit_t rabbit)
{
    return rabbit.sexe == male;
}

/* --------------------------------------------------------------------------*/
/*  sexe_t is_female(rabbit_t rabbit)                                        */
/** permet de savoir si le lapin est une femelle
 *
 * @param rabbit un lapin
 * 
 * @return true si le lapin est une femelle
 **/
/*---------------------------------------------------------------------------*/
sexe_t is_female(rabbit_t rabbit)
{
    return rabbit.sexe == female;
}

/* --------------------------------------------------------------------------*/
/*  Boolean give_birth(rabbit_t rabbit)                                      */
/** permet de savoir si le lapin donne naissance à une portée
 *
 * @param rabbit un lapin
 * 
 * @return true si le lapin donne naissance
 **/
/*---------------------------------------------------------------------------*/
Boolean give_birth(rabbit_t rabbit)
{
    if(is_female(rabbit)) {
        if(rabbit.nb_years > 0) {
            return true;
        }
    }
    return false;
}


/* --------------------------------------------------------------------------*/
/*  Boolean survive(rabbit_t rabbit)                                         */
/** permet de savoir si le lapin survit jusqu'à l'année suivante
 *
 * @param rabbit un lapin
 * 
 * @return true si le lapin survit
 **/
/*---------------------------------------------------------------------------*/
Boolean survive(rabbit_t rabbit)
{
    double percent;

    if(rabbit.nb_years < 1) {
        percent = 0.35;
    }
    else {
        percent = 0.5;
        if(rabbit.nb_years > 10) {
            percent -= (rabbit.nb_years - 10) * 0.1;
        }
    }
    if(genrand_real2() > percent) {
        return false;
    }
    return true;
}


/* --------------------------------------------------------------------------*/
/*  Boolean is_alive(rabbit_t rabbit)                                        */
/** retourne la variable bouléene alive du lapin
 *
 * @param rabbit un lapin
 * 
 * @return true si le lapin est en vie
 **/
/*---------------------------------------------------------------------------*/
Boolean is_alive(rabbit_t rabbit)
{
    return rabbit.alive;
}

/* --------------------------------------------------------------------------*/
/*  list_rabbit_t give_birth_all(list_rabbit_t list_rabbit)                  */
/** ajoute tout les nouveaux nés dans la liste de lapins
 *
 * @param list_rabbit une liste de lapin
 * 
 * @return la nouvelle liste de lapins après insertion des nouveaux nés
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t give_birth_all(list_rabbit_t list_rabbit)
{
    int           nb_liters;
    int           nb_birth;
    rabbit_t      rabbit;
    list_rabbit_t ltmp = list_rabbit;
    while(ltmp != NULL) {
        if(give_birth(ltmp->rabbit)) {
            nb_liters = (int)round(uniform(5, 7));
            for(int i = 0; i < nb_liters; i++) {
                nb_birth = (int)round(uniform(3, 6));
                for(int j = 0; j < nb_birth; j++) {
                    rabbit      = new_rabbit(0);
                    list_rabbit = add_head(list_rabbit, rabbit);
                }
            }
        }

        ltmp = ltmp->next;
    }
    return list_rabbit;
}


/* --------------------------------------------------------------------------*/
/*  list_rabbit_t survive_all(list_rabbit_t list_rabbit)                     */
/** change la valeur du bouléen alive pour tous les lapins de la liste
 *
 * @param list_rabbit une liste de lapin
 * 
 * @return la nouvelle liste de lapins après modification du bouléen
 **/
/*---------------------------------------------------------------------------*/
list_rabbit_t survive_all(list_rabbit_t list_rabbit)
{
    list_rabbit_t ltmp = list_rabbit;
    while(ltmp != NULL) {
        ltmp->rabbit.alive = survive(ltmp->rabbit);
        ltmp->rabbit.nb_years++;
        ltmp = ltmp->next;
    }
    return list_rabbit;
}

/* --------------------------------------------------------------------------*/
/*  void realistic_simulation()                                              */
/** fonction pour réaliser une simulation d'évolution de population de lapin 
 sur plusieurs années
 **/
/*---------------------------------------------------------------------------*/
void realistic_simulation()
{
    // initialisation de la liste avec quelques lapins
    int           nb_rabbit = 1;
    list_rabbit_t l         = new_list();
    for(int i = 0; i < nb_rabbit; i++) {
        l = add_head(l, new_rabbit2(5, male));
        l = add_head(l, new_rabbit2(5, female));
    }

    for(int years = 0; years < 15; years++) {
        l = give_birth_all(l);
        l = survive_all(l);
        l = delete_dead(l);

        printf("nb_years : %d, nb_rabbits : %d\n", years + 1, size_list(l));
        nb_loop++;
    }
}
