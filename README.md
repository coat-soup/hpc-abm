# Overview
This is basic immigration simulation using agent-based-modelling.

There are four countries tracking population, capacity, prosperity, worker force, and strife/conflict, and agents move between these countries based on these factors and personal needs such as immigration difficulty and distance.

# Simulation results
This is a very basic model to demonstrate and explore the benefits of high performance computing in this context. That said, the model still does a very good of representing flow and immigration trends between countries, especially regarding the effects of unforeseen events forcing people to flee their homes.

The four countries are set up to represent different points in the socioeconomic scale, and running the model with just that metric resulted in some very predictable, auto-balancing behaviour. Introducing strife into the migration calculations however had a very interesting effect on the simulation, as one country undergoing a crisis would affect also every other country as its agents fled en masse, tipping the economy across the board and reshuffling all the trends.

# Parallelisation analysis
The program consists of two main loops which run every simulation round.
The first loop handles each country, updating prosperity, work force values, and strife calculations.
The second loop handles the agents, updating country appeal values and handling immigration.

## Runtime statistics:
### Benchmark
- At `10,000` agents and `2,000` rounds, the simulation takes 6.08-6.10 seconds to run in <u>**serial**</u>.
- At `10,000` agents and `2,000` rounds, the simulation takes 0.85-0.94 seconds to run in <u>**parallel**</u>.

### Agent based tests
- At `50,000` agents and `2,000` rounds, the simulation takes 29.80-30.41 seconds to run in <u>**serial**</u>.
- At `50,000` agents and `2,000` rounds, the simulation takes 3.66-3.75 seconds to run in <u>**parallel**</u>.


- At `100,000` agents and `2,000` rounds, the simulation takes 58.00-59.43 seconds to run in <u>**serial**</u>.
- At `100,000` agents and `2,000` rounds, the simulation takes 6.94-7.15 seconds to run in <u>**parallel**</u>.

### Round based tests
- At `10,000` agents and `5,000` rounds, the simulation takes 14.69-14.72 seconds to run in <u>**serial**</u>.
- At `10,000` agents and `5,000` rounds, the simulation takes 2.27-2.28 seconds to run in <u>**parallel**</u>.


- At `10,000` agents and `10,000` rounds, the simulation takes 31.70-31.72 seconds to run in <u>**serial**</u>.
- At `10,000` agents and `10,000` rounds, the simulation takes 4.44-4.71 seconds to run in <u>**parallel**</u>.

# Conclusion
Parallelisation is an excellent tool for speeding up agent based modelling, as the process is many, many small decisions run over time, which classic HPC methods are perfect for.

With the data collected above, it shows that a speedup of up to 8.5 times is achievable with this model, with both number of agents and number of rounds scaling linearly.

Agent based modelling proves an exceptional solution to this problem, as the benefits of individual agents far outweighs other methods in the dynamic nature of discrete decision-making, and the incredible capacity for optimisation with high performance computing results in ABM being efficient, accurate, dynamic, and fast.