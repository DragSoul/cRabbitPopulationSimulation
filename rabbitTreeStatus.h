/**
 * \file rabbitTreeStatus.h
 * \author Aurelien DOUARD et Anthony BERTRAND
 * \brief Programmes pour réaliser une simulation stocastique de l'évolution
 d'une population de lapin avec des arbres d'états
 * \version 0.1 \date 16 mars 2020
 **/

#ifndef RTS_H
#define RTS_H

#include "mt19937ar.h"
#include "reverseDistLow.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------------------*/
/**
 * \struct configSimu_t
 * \brief configuration d'une simulation
 */
/*---------------------------------------------------------------------------*/
typedef struct {
    int      maxBabyPerLitter; /*!< nombre Max de bébé par portées           */
    int      minBabyPerLitter; /*!< nombre min de bébé par portées           */
    double   littleRabbitSurvRate; /*!< taux de survie d'un bébé lapin       */
    double   rabbitSurvRate; /*!< taux de survie d'un lapin adulte           */
    double   rateDisminish; /*!< taux de survie perdu après ageDisminish     */
    int      ageDisminish; /*!< age où les lapin perde du taux de survie     */
    int      minLitterPerYear; /*!< nombre min de portées par ans            */
    int      maxLitterPerYear; /*!< nombre max de portées par ans            */
    double * probaLittersYear;  /*!< probabilités de portées                 */ 
    double * probaLittersBabys; /*!< probabilités de bébé                    */ 
    int      maxRabbitYear; /*!< age mas des lapins                          */
    int      maxYear; /*!< nombre d'années de simulation                     */
    int      initPredator; /*!< mois a partir duquel les bébé peuvent mourir */
} configSimu_t;

/* --------------------------------------------------------------------------*/
/*  unsigned long realistic_simulation_TS(configSimu_t config)               */
/** fonction pour réaliser une simulation d'évolution de population de lapin 
 sur plusieurs années avec les configurations données
 *
 * @param  config configuration de la simulation
 * @return nombre de lapin final
 **/
/*---------------------------------------------------------------------------*/
unsigned long realistic_simulation_TS(configSimu_t config);

#endif