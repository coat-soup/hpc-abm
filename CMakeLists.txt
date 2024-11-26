cmake_minimum_required(VERSION 3.26)
project(hpc_abm)

set(CMAKE_CXX_STANDARD 17)

add_executable(hpc_abm src/main.cpp
        src/country.cpp
        src/agent.cpp)