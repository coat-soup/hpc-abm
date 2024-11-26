#define PROSP_SPEED 0.02

#ifndef HPC_ABM_COUNTRY_H
#define HPC_ABM_COUNTRY_H

#include <iostream>
#include <string>

class Country {
public:
    std::string name;
    int population;
    int population_capacity;

    float prosperity;
    int totalWorkerValue;
    Country(std::string n, int cap, float prosp){
        name = n;
        population_capacity = cap;
        prosperity = prosp;
        population = 0;
        totalWorkerValue = 0;
    };
    std::string toString(){
        return name + ":\n"
        + "pop: " + std::to_string(population) + "\n"
        + "prosp: " + std::to_string(prosperity) + "\n"
        + "worker val: " + std::to_string( totalWorkerValue) + "\n";
    }
    void UpdateProsperity(){
        prosperity += PROSP_SPEED * totalWorkerValue;
    }

    const float CalculateAppeal(){
        return prosperity *  (1.0 -  population/population_capacity);
    }
};

#endif
