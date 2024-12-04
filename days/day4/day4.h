#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../tools/benchmark.h"

class Day4 {
public:
    Day4();

    void part1();
    void part2();
private:
    typedef std::vector<std::string> word_search;

    word_search readFile(const std::string path);
    word_search puzzle;

    bool checkHorizontal(const int row, const int col);
    bool checkVertical(const int row, const int col);
    bool checkDiagonalA(const int row, const int col);
    bool checkDiagonalB(const int row, const int col);

    bool checkXmas(const int row, const int col);
};

