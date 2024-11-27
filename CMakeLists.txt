cmake_minimum_required(VERSION 3.26)
project(hpc_abm)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(hpc_abm src/main.cpp
        src/country.cpp
        src/agent.cpp)

target_link_libraries(hpc_abm PRIVATE OpenMP::OpenMP_CXX)