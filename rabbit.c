#include "rabbit.h"

int nb_loop = 1;
//creer automatiquement un lapin male ou femele
rabbit_t new_rabbit(int month)
{
    rabbit_t rabbit;
    rabbit.nb_month = month;
    rabbit.alive = true;
    rabbit.sexe = round(genrand_real2());
    return rabbit;
}


sexe_t is_male(rabbit_t rabbit)
{
    return rabbit.sexe == male;
}


sexe_t is_female(rabbit_t rabbit)
{
    return rabbit.sexe == female;
}


//renvoie true si la lapine donne naissance (pas encore randomiser)
Boolean give_birth(rabbit_t rabbit)
{
    if(is_female(rabbit))
    {
        if(rabbit.nb_month > 4)
        {
            return true;
        }
    }
    return false;
}


//TODO décider dès la naissance si le lapin survit à son enfance
    //ou non faire une proba cumulée sur les 5 mois de son enfance.
    //Quand le lapin passe à l'age adulte/vieux, re-decider de
    //sa survie + proba cumulée (à rajouter dans la structure)
    //pb : peu de lapin mourront vers 6 mois car la proba
    //cumulée sera faible au début... 

//renvoie true si le lapin survit
Boolean survive(rabbit_t rabbit)
{
    double random = genrand_real2();
    //printf("nb_loop = %d\t%f\t", nb_loop, random);
    if(rabbit.nb_month < 6)
    {
        //printf("%d\n", random < 0.35);
        return random < 0.35;
    }
    if(rabbit.nb_month < 132)
    {
        //printf("%d\n", random < 0.5);
        return random < 0.5;
    }
    if(rabbit.nb_month < 144)
    {
        //printf("%d\n", random < 0.4);
        return random < 0.4;
    }
    if(rabbit.nb_month < 156)
    {
        //printf("%d\n", random < 0.3);
        return random < 0.3;
    }
    if(rabbit.nb_month < 178)
    {
        //printf("%d\n", random < 0.2);
        return random < 0.2;
    }
    if(rabbit.nb_month < 180)
    {
        //printf("%d\n", random < 0.1);
        return random < 0.1;
    }
    return false;
}


Boolean is_alive(rabbit_t rabbit)
{
    return rabbit.alive;
}


//renvoie la liste avec les naissances (pas encore essayer 
//car doit d'abord enlever les lapins morts)
list_rabbit_t give_birth_all(list_rabbit_t list_rabbit)
{
    int random = (int)round(uniform(3, 6));
    rabbit_t rabbit;
    list_rabbit_t ltmp = list_rabbit;
    while(ltmp != NULL)
    {
        if(give_birth(ltmp->rabbit))
        {
            for(int i = 0; i < random; i++)
            {
                rabbit = new_rabbit(0);
                list_rabbit = add_head(list_rabbit, rabbit);
            }
        }
        
        ltmp = ltmp->next;
    }
	return list_rabbit;
}


//renvoie la liste avec les changements au niveau du booleen 'alive'
list_rabbit_t survive_all(list_rabbit_t list_rabbit)
{
	list_rabbit_t ltmp = list_rabbit;
    while(ltmp != NULL)
    {
        ltmp->rabbit.alive = survive(ltmp->rabbit);
        ltmp->rabbit.nb_month++;
        ltmp = ltmp->next;
    }
	return list_rabbit;
}


void realistic_simulation()
{
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    //initialisation de la liste avec quelques lapins
    int nb_rabbit = 20;
    list_rabbit_t l = new_list();
    for(int i = 0; i < nb_rabbit; i++){
        l = add_head(l, new_rabbit(5));
    }


    for(int month = 0; month < 5; month++){
        //vérifier qu'il reste au moins un male...
        l = give_birth_all(l);
        printf("after  birth %d : \n", nb_loop);
        display_rabbit_all(l);

        l = survive_all(l);
        
        l = delete_dead(l);
        printf("after  death %d : \n", nb_loop);
        display_rabbit_all(l);
        nb_loop++;
    }
    //display_death(l);
}