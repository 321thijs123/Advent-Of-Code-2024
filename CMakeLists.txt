project(HelloWorld)
cmake_minimum_required(VERSION 3.0)

add_executable(aoc 
    main.cpp
    days/day1/day1.cpp
    days/day2/day2.cpp
    days/day3/day3.cpp
    days/day4/day4.cpp
    tools/benchmark.cpp
)
