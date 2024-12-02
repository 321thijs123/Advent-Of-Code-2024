#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include "../../tools/benchmark.h"

class Day2 {
public:
    Day2();

    void part1();
    void part2();
private:
    typedef std::vector<int> levels;
    typedef std::vector<levels> report_list;

    report_list readFile(const std::string path);
    report_list reports;

    bool checkSafety(const levels report);
    bool checkSafetyDampener(const levels report);
    bool checkSafety(const int a, const int b, const bool increasing);
    levels getAlternative(const levels report, const int i);
};

