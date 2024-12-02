#include "day2.h"

Day2::Day2(){
    reports = readFile("../inputs/day2/example.txt");

	std::cout << " ---- Day 2 ---- " << std::endl;

	benchmark([this]() {this->part1();});
	benchmark([this]() {this->part2();});
}

Day2::report_list Day2::readFile(const std::string path){
	std::fstream inputFile(path, std::ios_base::in);

	report_list input;

    std::string line;

	while (getline(inputFile, line)) {
		std::istringstream reportStream(line);

        int level;

        std::vector<int> report;

        while (reportStream >> level)
            report.push_back(level);
        
        input.push_back(report);
	}

	return input;
}

bool Day2::checkSafety(const int a, const int b, const bool increasing) {
    if (increasing != (a > b)) return false;
    if (a == b) return false;
    if (abs(a - b) > 3) return false;

    return true;
}

bool Day2::checkSafety(const levels report) {
    bool increasing = report[1] > report[0];
    
    for (int i = 1; i < report.size(); i++) {

        if (!checkSafety(report[i], report[i - 1], increasing)) return false;
    }

    return true;
}

Day2::levels Day2::getAlternative(const levels report, const int i) {
    levels alternative = report;
    alternative.erase(alternative.begin() + i);

    return alternative;
}

bool Day2::checkSafetyDampener(const levels report) {
    bool increasing = report[1] > report[0];
    
    for (int i = 1; i < report.size(); i++) {
        if (!checkSafety(report[i], report[i - 1], increasing)){
            if (checkSafety(getAlternative(report, i))) return true;
            if (checkSafety(getAlternative(report, i - 1))) return true;
            if (i == 2 && checkSafety(getAlternative(report, 0))) return true;
            
            return false;
        };
    }

    return true;
}

void Day2::part1() {
	std::cout << "Part 1" << std::endl;

    int safeCount = 0;
    for (levels report : reports) {
        const bool safe = checkSafety(report);

        safeCount += safe;
    }

    std::cout << safeCount << " reports are safe." << std::endl;
}

void Day2::part2() {
	std::cout << std::endl << "Part 2" << std::endl;

    int safeCount = 0;
    for (levels report : reports) {
        const bool safe = checkSafetyDampener(report);

        safeCount += safe;
    }

    std::cout << safeCount << " reports are safe." << std::endl;
}
