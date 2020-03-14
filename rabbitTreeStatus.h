#ifndef RTS_H
#define RTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mt19937ar.h"
#include "reverseDistLow.h"

typedef struct {
    int maxBabyPerLitter;
    int minBabyPerLitter;
    double littleRabbitSurvRate;
    double rabbitSurvRate;
    double rateDisminish;
    int ageDisminish;
    int minLitterPerYear;
    int maxLitterPerYear;
    double *probaLittersYear; // tab len = maxLitterPerYear - minLitterPerYear
    double *probaLittersBabys; // tab len = maxBabyPerLitter - minBabyPerLitter
    int maxRabbitYear;
    int maxYear;
    int initPredator; // month when predator begin their job
}configSimu_t;

void realistic_simulation_TS(configSimu_t config);

#endif