#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include "../../tools/benchmark.h"

class Day5 {
public:
    Day5();

    void part1();
    void part2();
private:
    typedef std::vector<int> page_list;
    typedef std::vector<page_list> page_lists;
    
    void readFile(const std::string path);

    page_lists updates;
    bool ruleMap[100][100] = { false };

    bool isRight(page_list &update);
    int orderPages(page_list &update);
};

