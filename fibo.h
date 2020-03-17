/**
 * \file fibo.h
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour calculer les termes de la suite de Fibonacci.
 * \version 0.1
 * \date 16 mars 2020
 **/

#ifndef FIBO_H
#define FIBO_H

#include <math.h>
#include <stdio.h>

unsigned long fibo_recursif(int n);
unsigned long fibo_recurence(int n);
unsigned long fibo_explicite(int n);

#endif