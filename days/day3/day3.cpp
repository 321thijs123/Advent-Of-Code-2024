#include "day3.h"

Day3::Day3(){
    memory = readFile("../inputs/day3/example2.txt");

	std::cout << " ---- Day 3 ---- " << std::endl;

	benchmark([this]() {this->part1();});
	benchmark([this]() {this->part2();});
}

std::string Day3::readFile(const std::string path){
	std::ifstream inputFile(path);

    std::string content((std::istreambuf_iterator<char>(inputFile)),
                 std::istreambuf_iterator<char>());

    return content;
}

int Day3::readInt(int &pos){
    int val = 0;
    
    while (memory[pos] <= '9' && memory[pos] >= '0') {
        val = val * 10 + memory[pos] - '0';

        pos++;
    }

    return val;
}

void Day3::part1() {
	std::cout << "Part 1" << std::endl;

    size_t pos = 0;

    int sum = 0;

    for (int pos = 0; pos < memory.size() - 4; pos++) {
        if (memory.substr(pos, 4) != "mul(") continue;

        pos += 4;

        const int valA = readInt(pos);

        if (memory[pos] != ',') continue;

        pos++;

        const int valB = readInt(pos);

        if (memory[pos] != ')') continue;

        sum += valA * valB;
    }

    std::cout << "Sum: " << sum << std::endl;
}

void Day3::part2() {
	std::cout << std::endl << "Part 2" << std::endl;

    size_t pos = 0;

    int sum = 0;
    bool enabled = true;

    for (int pos = 0; pos < memory.size() - 4; pos++) {
        if (memory.substr(pos, 4) == "mul("){
            pos += 4;

            if (enabled) {
                const int valA = readInt(pos);

                if (memory[pos] != ',') continue;

                pos++;

                const int valB = readInt(pos);

                if (memory[pos] != ')') continue;

                sum += valA * valB;
            }
        }
        else if (memory.substr(pos,2) == "do"){
            pos += 2;

            if (memory.substr(pos, 2) == "()") {
                pos += 1;
                enabled = true;
            }
            else if (memory.substr(pos, 5) == "n't()") { 
                pos += 4;
                enabled = false;
            }
        }
    }

    std::cout << "Sum: " << sum << std::endl;
}
