#define AGENTS 100
#define ROUNDS 20

#include <iostream>

#include "agent.h"
#include "country.h"


int main() {
    Country countries[4] = {Country("Utopia", 30, 100),
                            Country("Midtown", 20, 50),
                            Country("5th World", 10, 15),
                            Country("Brazil", 40, -30)};
    Agent agents[AGENTS];
    for(int i = 0; i < AGENTS; i++){
                                // value from -5 to 15
        agents[i] = Agent(10 + (rand()%15), &countries[rand()%4]);
    }

    for(int i = 0; i < ROUNDS; i++){
        std::cout << "----" << "Sim step " << i << " ----" << std::endl;

        // Update country prosperity
        for (int c = 0; c < 4; c++){
            std::cout << countries[c].toString() << std::endl;
            countries[c].UpdateProsperity();
        }

        for(int a = 0; a < AGENTS; a++){
            Country bestCountry = countries[agents[a].EvaluateMigration(countries)];
            if(&bestCountry == agents[a].country && rand() % 5 == 1){
                //printf("Same country, staying.");
            }
            else{
                agents[a].Immigrate(&bestCountry);
                std::cout << "Agent " << a << " moving to " << bestCountry.name << std::endl;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}