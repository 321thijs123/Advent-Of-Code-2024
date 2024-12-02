#include "day1.h"

Day1::Day1(){
    input = readFile("../inputs/day1/example.txt");

	std::cout << " ---- Day 1 ---- " << std::endl;

	benchmark([this]() {this->part1();});
	benchmark([this]() {this->part2();});
}

Day1::lists Day1::readFile(std::string path){
	std::fstream inputFile(path, std::ios_base::in);

	lists input;

	int a, b;

	while (inputFile >> a  >> b) {
		input.first.push_back(a);
		input.second.push_back(b);
	}

	return input;
}

void Day1::part1() {
	lists input = this->input;

	std::cout << "Part 1" << std::endl;

	int totalDistance = 0;
	
	while (input.first.size() > 0){
		int iA = 0;
		int iB = 0;

		for (int i = 0; i < input.first.size(); i++) {
			if (input.first[i] < input.first[iA])
				iA = i;
			
			if (input.second[i] < input.second[iB])
				iB = i;
		}

		const int dist = abs(input.first[iA]- input.second[iB]);

		totalDistance += dist;

		input.first.erase(input.first.begin() + iA);
		input.second.erase(input.second.begin() + iB);
	}

	std::cout << "Total distance: " << totalDistance << std::endl;
}

void Day1::part2() {
	std::cout << std::endl << "Part 2" << std::endl;

	int similarity = 0;

	for (const int first : input.first){
		for (const int second : input.second){
			if (first == second) {
				similarity += first;
			}
		}
	}

	std::cout << "Similarity score: " << similarity << std::endl;
}
