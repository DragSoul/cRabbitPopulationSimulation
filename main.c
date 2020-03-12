#include <stdio.h>
#include "fibo.h"
#include "rabbit.h"
#include "rabbitTreeStatus.h"

void question1()
{
    int n1 = fibo_recurente(15);
    int n2 = fibo_recursif(15);
    int n3 = fibo_explicite(15);
    printf("%d\t%d\t%d\n", n1, n2, n3);
}


int main()
{
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    //question1();
    //realistic_simulation2();

    int nbExp = 10;
    double tabProbaLitter[5] = {0.1, 0.2, 0.4, 0.2, 0.1};
    double tabProbaBabys[4] = {0.25,0.25,0.25,0.25};
    configSimu_t config;
    config.maxRabbitYear = 15;
    config.ageDisminish = 10;
    config.littleRabbitSurvRate = 0.35;
    config.maxBabyPerLitter = 6;
    config.maxLitterPerYear = 8;
    config.maxYear = 10;
    config.minBabyPerLitter = 3;
    config.minLitterPerYear = 4;
    config.probaLittersBabys = tabProbaBabys;
    config.probaLittersYear = tabProbaLitter;
    config.rabbitSurvRate = 0.6;
    config.rateDisminish = 0.1;

    for(int i = 0; i < nbExp; i++)
    {
        realistic_simulation_TS(config);
        printf("\n");
    }
    return 0;
}