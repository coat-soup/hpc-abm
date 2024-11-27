#ifndef HPC_ABM_AGENT_H
#define HPC_ABM_AGENT_H

#include "country.h"
#include <iostream>
#include <string>


class Agent {
public:
    int workerValue;
    Country *country;
    Agent(int value, Country *c) : workerValue(value), country(c) {
        country->population+=1;
        country->totalWorkerValue += workerValue;
    };
    Agent(Country *c=nullptr) : workerValue(0), country(c) {};

    int EvaluateMigration(Country countries[4]){
        int best = 0;
        float bestVal = 0;
        for (int c = 0; c < 4; c++){
            float appeal = countries[c].CalculateAppeal() - Position::Distance(countries[c].position, country->position);

            if(c == 0 || appeal > bestVal){
                bestVal = appeal;
                best = c;
            }
        }

        return best;
    }

    void Immigrate(Country *newCountry){
        country->population -= 1;
        country->totalWorkerValue -= workerValue;

        newCountry->population += 1;
        newCountry->totalWorkerValue += workerValue;

        country = newCountry;
    }
};


#endif