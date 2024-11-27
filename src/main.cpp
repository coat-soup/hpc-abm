#define AGENTS 100000
#define ROUNDS 2000
#define VERBOSE false
#define PARALLEL true
#include <iostream>
#include <omp.h>

#include "agent.h"
#include "country.h"

int main() {
    Country countries[4] = {Country("Utopia", Position(-3, 4), 3 * AGENTS / 10, 0, 100),
                            Country("Midtown", Position(1, 2), 2 * AGENTS / 10, 5, 50),
                            Country("5th World", Position(0, 4), 1 * AGENTS / 10, 20, 15),
                            Country("Brazil", Position(-1, -1), 4 * AGENTS / 10, 50, -30)};

    Agent agents[AGENTS];
    for (int i = 0; i < AGENTS; i++) {
        // Value from -1 to 2
        agents[i] = Agent(1 + (rand() % 3), &countries[rand() % 4]);
    }

    // Print initial state
    std::cout << "INITIAL STATE:" << std::endl;
    for (int c = 0; c < 4; c++) {
        std::cout << countries[c].toString() << std::endl;
    }

    // Start timing
    double start_time = omp_get_wtime();

    // Main simulation loop
    for (int i = 0; i < ROUNDS; i++) {
        if (VERBOSE) std::cout << "----" << "Sim step " << i << " ----" << std::endl;

        // Update country prosperity
#if PARALLEL
#pragma omp parallel for
#endif
        for (int c = 0; c < 4; c++) {
            if (VERBOSE) std::cout << countries[c].toString() << std::endl;
            countries[c].UpdateProsperity();

            if (rand() % 200 == 1) {
                countries[c].strife_counter += 20 + rand() % 30;  // 1 in 200 chance of strife (20-30 rounds)
            }
        }

        // Agents evaluate migration and potentially immigrate
#if PARALLEL
#pragma omp parallel for
#endif
        for (int a = 0; a < AGENTS; a++) {
            Country* bestCountry = &countries[agents[a].EvaluateMigration(countries)];
            if (bestCountry != agents[a].country && rand() % 100 == 1) {  // 1 in 100 chance of immigrating
                agents[a].Immigrate(bestCountry);
            }
        }

        if (VERBOSE) std::cout << std::endl;
    }

    // End timing
    double end_time = omp_get_wtime();
    double elapsed_time = end_time - start_time;

    // Print final results
    std::cout << "\nFINAL RESULTS:" << std::endl;
    for (int c = 0; c < 4; c++) {
        std::cout << countries[c].toString() << std::endl;
    }

    // Print time taken
    std::cout << "\nTime taken: " << elapsed_time << " seconds." << std::endl;

    return 0;
}
