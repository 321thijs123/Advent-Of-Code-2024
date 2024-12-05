#include "day5.h"

Day5::Day5(){
    readFile("../inputs/day5/example.txt");

	std::cout << " ---- Day 5 ---- " << std::endl;

	benchmark([this]() {this->part1();});
	benchmark([this]() {this->part2();});
}

void Day5::readFile(const std::string path){
	std::fstream inputFile(path, std::ios_base::in);

    std::string line;

	while (getline(inputFile, line)) {
        const size_t pairSplit = line.find('|');

        if (pairSplit != std::string::npos){
            const std::string strFirst = line.substr(0, pairSplit);
            const std::string strSecond = line.substr(pairSplit + 1, line.size() - pairSplit);

            const int first = std::stoi(strFirst);
            const int second = std::stoi(strSecond);

            ruleMap[first][second] = true;
        }
        else if (line.find(',') != std::string::npos) {
            int page;

            page_list update;

            std::stringstream ss(line); 

            while(ss>>page){
                update.push_back(page);
                if (ss.peek() == ',')
                    ss.ignore();
            }

            updates.push_back(update);
        }
    }
}

bool Day5::isRight(page_list &update){
    for (int i = 0; i < update.size() - 1; i++){
        if (!ruleMap[update[i]][update[i + 1]]){
            return false;
        }
    }

    return true;
}

void Day5::part1() {
	std::cout << "Part 1" << std::endl;

    int sum = 0;

    for (page_list update : updates){
        if (isRight(update)) sum += update[(update.size() - 1) / 2];
    }

    std::cout << "Sum: " << sum << std::endl;
}

int Day5::orderPages(page_list &update) {
    bool right = false;

    while (!right) {
        right = true;

        for (int i = 0; i < update.size() - 1; i++) {
            if (!ruleMap[update[i]][update[i + 1]]) {
                right = false;

                const int swapVar = update[i];
                update[i] = update[i + 1];
                update[i + 1] = swapVar;
            }
        }
    }

    return update[(update.size() - 1) / 2];
}

void Day5::part2() {
	std::cout << std::endl << "Part 2" << std::endl;

    int sum = 0;

    for (page_list &update : updates) {
        if (!isRight(update)) sum += orderPages(update);
    }

    std::cout << "Sum: " << sum << std::endl;
}
