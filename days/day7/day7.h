#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include "../../tools/benchmark.h"

class Day7 {
public:
    Day7();

    void part1();
    void part2();
private:
    void readFile(const std::string);

    struct Equation {
        long long result;
        std::vector<long long> params;
    };

    enum Operator {
        add,
        multiply,
        concatenate
    };

    std::vector<Equation> equations;

    long long calculate(const std::vector<long long> &params, const std::vector<Operator> &operators);
    bool tryCombinations(const int i, const Equation &equation, std::vector<Operator> &operators);
    bool tryCombinations2(const int i, const Equation &equation, std::vector<Operator> &operators);
    void concatInts(long long &a, const long long b);
};
