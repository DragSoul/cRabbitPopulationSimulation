#ifndef RABBIT_H
#define RABBIT_H

#include <stdio.h>
#include<stdlib.h>
#include "fibo.h"
#include "rabbit_list.h"
#include "mt19937ar.h"

rabbit_t new_rabbit(int years);
rabbit_t new_rabbit2(int years, sexe_t sexe);
sexe_t is_male(rabbit_t rabbit);
sexe_t is_female(rabbit_t rabbit);
Boolean give_birth(rabbit_t rabbit);
Boolean survive(rabbit_t rabbit);
Boolean is_alive(rabbit_t rabbit);
list_rabbit_t survive_all(list_rabbit_t list_rabbit);

void realistic_simulation();



#endif