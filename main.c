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
    double tabProbaLitter[5] = {0.05, 0.3, 0.3, 0.3, 0.05};
    double tabProbaBabys[4] = {0.25,0.25,0.25,0.25};
    configSimu_t config;
    config.maxRabbitYear = 15;
    config.ageDisminish = 11;
    config.littleRabbitSurvRate = 0.35;
    config.maxBabyPerLitter = 6;
    config.maxLitterPerYear = 8;
    config.maxYear = 8;
    config.minBabyPerLitter = 3;
    config.minLitterPerYear = 4;
    config.probaLittersBabys = tabProbaBabys;
    config.probaLittersYear = tabProbaLitter;
    config.rabbitSurvRate = 0.5;
    config.rateDisminish = 0.1;
    realistic_simulation_TS(config);

    
    return 0;
}