#include <iostream>
#include <fstream>
#include <string>
#include "../../tools/benchmark.h"

class Day3 {
public:
    Day3();

    void part1();
    void part2();
private:
    std::string readFile(const std::string path);
    std::string memory;

    int readInt(int &pos);
};

