#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include "../../tools/benchmark.h"

class Day1 {
public:
    Day1();

    void part1();
    void part2();
private:
    typedef std::pair<std::vector<int>, std::vector<int>> lists;

    lists readFile(std::string path);
    lists input;
};
