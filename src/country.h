#define PROSP_SPEED 0.1

#ifndef HPC_ABM_COUNTRY_H
#define HPC_ABM_COUNTRY_H

#include <iostream>
#include <string>
#include <format>
#include <format>
#include <iostream>
#include <cmath>


class Position {
public:
    float x;
    float y;
    Position(float _x, float _y) : x(_x), y(_y){};
    static float Distance(Position a, Position b){
        return sqrtf(powf((a.x - b.x),2) + powf((a.y - b.y),2));
    }
};

class Country {
public:
    std::string name;
    Position position;
    int population;
    int population_capacity;
    int strife_counter;

    float prosperity;
    int totalWorkerValue;
    Country(std::string n, Position pos, int cap, int strife, float prosp) : position(pos) {
        name = n;
        population_capacity = cap;
        strife_counter = strife;
        prosperity = prosp;
        population = 0;
        totalWorkerValue = 0;
    };
    std::string toString(){
        return name + ":\n"
        + "pop: " + std::to_string(population) + "/" + std::to_string(population_capacity) + ", "
        + "prosp: " + std::to_string((int)prosperity) + ", "
        + "worker val: " + std::to_string( totalWorkerValue) + ", "
        + "strife: " + std::to_string( strife_counter) + ", "
        + "appeal: " + std::to_string(CalculateAppeal()) + "\n";
    }
    void UpdateProsperity(){
        prosperity += PROSP_SPEED * (((float)abs(population_capacity - population)/(float)population_capacity < 0.3f) ? 1 : -1);
        if(strife_counter > 0) strife_counter -= 1;
    }
    void CreateStrife(int length){
        strife_counter = length;
    }
    const float CalculateAppeal(){
        return 1.0f -  ((float)population/(float)population_capacity) - (float)strife_counter/5.0f;
        return prosperity *  (1.0 -  population/population_capacity);
    }
};

#endif
