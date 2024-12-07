#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../tools/benchmark.h"

class Day6 {
public:
    Day6();

    void part1();
    void part2();
private:
    void readFile(const std::string);

    std::vector<std::vector<bool>> map;
    std::vector<std::vector<bool>> visited;

    int guardX, guardY;

    enum direction{up, right, down, left};

    struct HistoryEntry {
        char state = 0b00000000;

        bool get(direction);
        void set(direction);
    };

    direction dir;

    friend direction operator++(direction& dir, int);

    bool moveGuard();
    void show(std::vector<std::vector<bool>>);
};
