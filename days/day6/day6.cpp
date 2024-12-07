#include "day6.h"

Day6::Day6(){
	std::cout << " ---- Day 6 ---- " << std::endl;

    const std::string filePath = "../inputs/day6/example.txt";

    readFile(filePath);
	benchmark([this]() {this->part1();});

    readFile(filePath);
	benchmark([this]() {this->part2();});
}

void Day6::readFile(const std::string path){
    map.clear();

    std::cout << "Reading map..." << std::endl;
    
	std::fstream inputFile(path, std::ios_base::in);

    std::string line;

    int y = 0;

	while (getline(inputFile, line)) {
        if (line.size() > 0){
            std::vector<bool> mapRow;

            for (int x = 0; x < line.size(); x++) {
                mapRow.push_back(line[x] == '#');

                if (line[x] == '^') {
                    guardX = x;
                    guardY = y;
                }
            }

            map.push_back(mapRow);
            y++;
        }
    }

    dir = up;

    visited = std::vector<std::vector<bool>>(map.size(), std::vector<bool>(map[0].size(), false));
    // show(map);
}

Day6::direction operator++(Day6::direction& dir, int){
    Day6::direction old = dir;
    switch(dir) {
        case Day6::direction::up:    dir = Day6::direction::right; return old;
        case Day6::direction::right: dir = Day6::direction::down;  return old;
        case Day6::direction::down:  dir = Day6::direction::left;  return old;
        default:                     dir = Day6::direction::up;    return old;
    }
}

bool Day6::moveGuard() {
    switch (dir) {
    case up:
        if (guardY > 0) {
            if (map[guardY - 1][guardX]) {
                dir++;
            }
            else{
                guardY = guardY - 1;
            }
            return true;
        }
        break;
    case right:
        if (guardX < map[0].size() - 1) {
            if (map[guardY][guardX + 1]) {
                dir++;
            }
            else{
                guardX = guardX + 1;
            }
            return true;
        }
        break;
    case down:
        if (guardY < map.size() - 1) {
            if (map[guardY + 1][guardX]) {
                dir++;
            }
            else{
                guardY = guardY + 1;
            }
            return true;
        }
        break;
    case left:
        if (guardX > 0) {
            if (map[guardY][guardX - 1]) {
                dir++;
            }
            else{
                guardX = guardX - 1;
            }
            
            return true;
        }
        break;
    }

    return false;
}

void Day6::show(std::vector<std::vector<bool>> map){
    for (std::vector<bool> &row : map){
        for (bool point : row) std::cout << (point ? "X" : ".");
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Day6::part1() {
	std::cout << "Part 1" << std::endl;

    int count = 0;

    do {
        count += !visited[guardY][guardX];
        visited[guardY][guardX] = true;
    } while(moveGuard());

    // show(visited);

    std::cout << "Visited " << count << " distinct positions" << std::endl;
}

bool Day6::HistoryEntry::get(direction dir) {
    switch(dir) {
        case direction::up:    return state & 0b1000000;
        case direction::right: return state & 0b0100000;
        case direction::down:  return state & 0b0010000;
        case direction::left:  return state & 0b0001000;
    }

    return false;
}

void Day6::HistoryEntry::set(direction dir) {
    switch(dir) {
        case direction::up:    state |= 0b1000000; break;
        case direction::right: state |= 0b0100000; break;
        case direction::down:  state |= 0b0010000; break;
        case direction::left:  state |= 0b0001000; break;
    }
}

void Day6::part2() {
	std::cout << std::endl << "Part 2" << std::endl;

    const int guardStartX = guardX;
    const int guardStartY = guardY;

    int count = 0;

    for (int obsY = 0; obsY < map.size(); obsY++) {
        for (int obsX = 0; obsX < map[0].size(); obsX++){
            if ((!map[obsY][obsX]) && !(obsX == guardStartX && obsY == guardStartY)){
                std::vector<std::vector<HistoryEntry>> dirHistory = std::vector<std::vector<HistoryEntry>>(map.size(), std::vector<HistoryEntry>(map[0].size()));

                guardX = guardStartX;
                guardY = guardStartY;
                dir = up;
                map[obsY][obsX] = true;

                do {
                    if (dirHistory[guardY][guardX].get(dir)) {
                        count++;
                        break;
                    }

                    dirHistory[guardY][guardX].set(dir);
                } while(moveGuard());

                map[obsY][obsX] = false;
            }
        }
    }

    std::cout << "Found " << count << " loop possibilites" << std::endl;
}
