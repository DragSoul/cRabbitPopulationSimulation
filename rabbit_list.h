#ifndef RABBIT_LIST_H
#define RABBIT_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef enum{male, female}sexe_t;
typedef enum{false, true}Boolean;

typedef struct{
    sexe_t sexe;
    int nb_month;
	Boolean alive;
}rabbit_t;


typedef struct link{
    rabbit_t rabbit;
    struct link *next;
}link_t, *list_rabbit_t;




list_rabbit_t new_list(void);
rabbit_t head(list_rabbit_t list_rabbit);
Boolean empty(list_rabbit_t list_rabbit);
list_rabbit_t add_head(list_rabbit_t list_rabbit, rabbit_t rabbit);
list_rabbit_t delete_head(list_rabbit_t list_rabbit);
int nb_element(list_rabbit_t list_rabbit);
void display_rabbit(rabbit_t rabbit);
void display_list(list_rabbit_t list_rabbit);
void display_death(list_rabbit_t list_rabbit);



#endif
