/**
 * \file rabbitTreeStatus.c
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour réaliser une simulation stocastique de l'évolution
 d'une population de lapin avec des arbres d'états
 * \version 0.1 \date 16 mars 2020
 **/

#include "rabbitTreeStatus.h"

/* --------------------------------------------------------------------------*/
/*  void checkMallocNull(void * tab)                                         */
/** vérifi si un malloc c'est bien passé
 *
 * @param  tab tableau
 * @return void
 **/
/*---------------------------------------------------------------------------*/
void checkMallocNull(void * tab)
{
    if(tab == NULL) {
        printf("pb malloc");
        exit(1);
    }
}

/* --------------------------------------------------------------------------*/
/*  unsigned long ** createRabbitTabZero(int maxRabbitYear)                  */
/** crée un tableau pour stocker des états de lapin, initialisé avec des zero
 *
 * @param  maxRabbitYear l'age maximum d'un lapin
 * @return un tableau de tableaux de unsigned long
 **/
/*---------------------------------------------------------------------------*/
unsigned long ** createRabbitTabZero(int maxRabbitYear)
{
    unsigned long ** rabbits = NULL;

    rabbits = malloc(sizeof(unsigned long *) * 2);
    checkMallocNull(rabbits);
    for(int i = 0; i < 2; i++) {
        rabbits[i] = calloc(maxRabbitYear, sizeof(unsigned long));
        checkMallocNull(rabbits[i]);
    }
    return rabbits;
}

/* --------------------------------------------------------------------------*/
/*  void copyRabitTab(unsigned long ** src, unsigned long ** dest,
                  int maxRabbitYear)                                         */
/** fonction pour copier des tableaux d'états de lapin
 *
 * @param  src tableau source
 * @param  dest tableau de destination
 * @param  maxRabbitYear l'age maximum d'un lapin
 * @return void
 **/
/*---------------------------------------------------------------------------*/
void copyRabitTab(unsigned long ** src, unsigned long ** dest,
                  int maxRabbitYear)
{
    for(int sex = 0; sex < 2; sex++) {
        for(int rabbitYear = 0; rabbitYear < maxRabbitYear; rabbitYear++) {
            dest[sex][rabbitYear] = src[sex][rabbitYear];
        }
    }
}


/* --------------------------------------------------------------------------*/
/*  int surviveRabbitYear(int old, configSimu_t config)                      */
/** fonction qui dit si un lapin survie ou non (renvoit 1 ou 0)
 *
 * @param  old age du lapin
 * @param  config configuration de la simulation
 * @return 1 ou 0
 **/
/*---------------------------------------------------------------------------*/
int surviveRabbitYear(int old, configSimu_t config)
{
    double percent;

    if(old < 1) {
        percent = config.littleRabbitSurvRate;
    }
    else {
        percent = config.rabbitSurvRate;
        if(old > config.ageDisminish) {
            percent -= (old - config.ageDisminish) * config.rateDisminish;
        }
    }
    if(genrand_real2() > percent) {
        return 0;
    }
    return 1;
}

/* --------------------------------------------------------------------------*/
/*  unsigned long makeBabys(int old, double cumulProbaLitter[],
                        double cumulProbaBabys[], int lenCumulProbaLitter,
                        int lenCumulProbaBabys, int minLitter, int minBaby)  */
/** fonction pour savoir combien de lapins va faire un lapin donné pendant une
année
 *
 * @param  old age du lapin
 * @param  cumulProbaLitter tableau de probabilité cumulé pour le nombre de 
 portée
 * @param  cumulProbaBabys tableau de probabilité cumulé pour le nombre de 
 bébés par portée
 * @param  lenCumulProbaLitter longeur du tableau de proba de portée
 * @param  lenCumulProbaBabys longeur du tableau de proba de bébés
 * @param  minLitter nombre minimum de portées
 * @param  minBaby nombre minimum de bébés
 * @return 1 ou 0
 **/
/*---------------------------------------------------------------------------*/
unsigned long makeBabys(int old, double cumulProbaLitter[],
                        double cumulProbaBabys[], int lenCumulProbaLitter,
                        int lenCumulProbaBabys, int minLitter, int minBaby)
{
    int litter, babys = 0;

    litter = minLitter + genRand_discDist(genrand_real2(), cumulProbaLitter,
                                          lenCumulProbaLitter);

    if(old < 0) {
        litter = 0; //"Sexual maturity is reachedbetween 5 to 8 months after the
                    // birth of baby rabbits, but you can simplify and retain an
                    // annual time step for the simulation"
    }
    for(int i = 0; i < litter; i++) {
        babys += minBaby + genRand_discDist(genrand_real2(), cumulProbaBabys,
                                            lenCumulProbaBabys);
    }
    return babys;
}

/* --------------------------------------------------------------------------*/
/*  unsigned long CalcSumYears(unsigned long ** tab, int maxOld)             */
/** fonction pour calculer la somme des lapins
 *
 * @param  tab tableau
 * @param  maxOld age max des lapins
 * @return la somme des lapins
 **/
/*---------------------------------------------------------------------------*/
unsigned long CalcSumYears(unsigned long ** tab, int maxOld)
{
    unsigned long sum = 0;
    for(int sex = 0; sex < 2; sex++) {
        for(int old = 0; old < maxOld; old++) {
            sum += tab[sex][old];
        }
    }
    return sum;
}

/* --------------------------------------------------------------------------*/
/*  void addBabys(unsigned long babys, unsigned long ** rabbit)              */
/** fonction pour ajouter les lapins a la liste des lapins
 *
 * @param  babys nombre de bébés a ajouter
 * @param  rabbit tableaux d'états de lapins
 * @return void
 **/
/*---------------------------------------------------------------------------*/
void addBabys(unsigned long babys, unsigned long ** rabbit)
{
    for(int i = 0; i < babys; i++) {
        rabbit[(int)round(genrand_real2())][0]++;
        ;
    }
}

/* --------------------------------------------------------------------------*/
/*  void free_double_tab(unsigned long ** tab, int n)                        */
/** fonction pour free un tableau de tableaux de unsigned long
 *
 * @param  tab tableau
 * @param  n nombre d'éléments dans le tableau
 * @return void
 **/
/*---------------------------------------------------------------------------*/
void free_double_tab(unsigned long ** tab, int n)
{
    for(int i = 0; i < n; i++) {
        free(tab[i]);
    }
    free(tab);
}

/* --------------------------------------------------------------------------*/
/*  unsigned long sum_array(unsigned long array[], int n)                    */
/** fonction pour faire la somme d'un tableaux de unsigned long
 *
 * @param  array tableau
 * @param  n nombre d'éléments dans le tableau
 * @return somme
 **/
/*---------------------------------------------------------------------------*/
unsigned long sum_array(unsigned long array[], int n)
{
    unsigned long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}

/* --------------------------------------------------------------------------*/
/*  unsigned long
rabbit_simu_iteration(configSimu_t config, unsigned long ** rabbits,
                      unsigned long ** rabbitsTmp, int year,
                      double * cumulProbaLitter, double * cumulProbaBabys,
                      int lenCumulProbaLitter, int lenCumulProbaBabys)       */
/** fonction qui réalise une itération de la simulation d'évolution de 
 population de lapin
 *
 * @param  config configuration de la simulation
 * @param  rabbits tableau d'états de lapins
 * @param  rabbitsTmp tableau d'états de lapins temporaire
 * @param  year année de l'iteration
 * @param  cumulProbaLitter tableau de probabilité cumulé pour le nombre de 
 portée
 * @param  cumulProbaBabys tableau de probabilité cumulé pour le nombre de 
 bébés par portée
 * @param  lenCumulProbaLitter longeur du tableau de proba de portée
 * @param  lenCumulProbaBabys longeur du tableau de proba de bébés
 * @param  n nombre d'éléments dans le tableau
 * @return nombre de bébés à ajouter
 **/
/*---------------------------------------------------------------------------*/
unsigned long
rabbit_simu_iteration(configSimu_t config, unsigned long ** rabbits,
                      unsigned long ** rabbitsTmp, int year,
                      double * cumulProbaLitter, double * cumulProbaBabys,
                      int lenCumulProbaLitter, int lenCumulProbaBabys)
{
    int           surv;
    unsigned long babys = 0;

    for(int sex = 0; sex < 2; sex++) {
        for(int old = 0; old < config.maxRabbitYear; old++) {
            for(int rab = 0; rab < rabbitsTmp[sex][old]; rab++) {
                if(config.initPredator < year) {
                    surv = surviveRabbitYear(old, config);
                }
                rabbits[sex][old]--;
                if(surv) {
                    if(sex == 0) {
                        babys += makeBabys(
                            old, cumulProbaLitter, cumulProbaBabys,
                            lenCumulProbaLitter, lenCumulProbaBabys,
                            config.minLitterPerYear, config.minBabyPerLitter);
                    }
                    if(old < config.maxRabbitYear) {
                        rabbits[sex][old + 1]++;
                    }
                }
            }
        }
    }
    return babys;
}

/* --------------------------------------------------------------------------*/
/*  unsigned long realistic_simulation_TS(configSimu_t config)               */
/** fonction pour réaliser une simulation d'évolution de population de lapin 
 sur plusieurs années avec les configurations données
 *
 * @param  config configuration de la simulation
 * @return nombre de lapin final
 **/
/*---------------------------------------------------------------------------*/
unsigned long realistic_simulation_TS(configSimu_t config)
{
    unsigned long ** rabbits    = NULL;
    unsigned long ** rabbitsTmp = NULL;

    int           surv = 1;
    unsigned long babys;
    unsigned long sum;

    double * cumulProbaLitter;
    double * cumulProbaBabys;

    int lenCumulProbaLitter, lenCumulProbaBabys;
    lenCumulProbaLitter =
        (config.maxLitterPerYear - config.minLitterPerYear) + 1;
    lenCumulProbaBabys =
        (config.maxBabyPerLitter - config.minBabyPerLitter) + 1;

    cumulProbaLitter =
        calcCumulProba(config.probaLittersYear, lenCumulProbaLitter);
    checkMallocNull(cumulProbaLitter);
    cumulProbaBabys =
        calcCumulProba(config.probaLittersBabys, lenCumulProbaBabys);
    checkMallocNull(cumulProbaBabys);

    rabbits    = createRabbitTabZero(config.maxRabbitYear);
    rabbitsTmp = createRabbitTabZero(config.maxRabbitYear);

    rabbits[0][1]++;
    rabbits[1][1]++;

    for(int year = 0; year < config.maxYear; year++) {
        babys = 0;
        copyRabitTab(rabbits, rabbitsTmp, config.maxRabbitYear);
        babys += rabbit_simu_iteration(config, rabbits, rabbitsTmp, year,
                                       cumulProbaLitter, cumulProbaBabys,
                                       lenCumulProbaLitter, lenCumulProbaBabys);
        sum = CalcSumYears(rabbits, config.maxRabbitYear);
        addBabys(babys, rabbits);
        printf(
            "%d : nbAdulte : %lu nbEnfant : %lu nbMale : %lu nbFemele : %lu\n",
            year, sum, babys, sum_array(rabbits[0], config.maxRabbitYear),
            sum_array(rabbits[1], config.maxRabbitYear));
    }

    unsigned long total = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < config.maxRabbitYear; j++) {
            total += rabbits[i][j];
        }
    }

    free_double_tab(rabbits, 2);
    free_double_tab(rabbitsTmp, 2);
    free(cumulProbaBabys);
    free(cumulProbaLitter);

    return total;
}