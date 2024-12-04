#include "day4.h"

Day4::Day4(){
    puzzle = readFile("../inputs/day4/example.txt");

	std::cout << " ---- Day 4 ---- " << std::endl;

	benchmark([this]() {this->part1();});
	benchmark([this]() {this->part2();});
}

Day4::word_search Day4::readFile(const std::string path){
	std::fstream inputFile(path, std::ios_base::in);

    word_search input;

    std::string line;

	while (getline(inputFile, line)) {
        if (line.size() != 0) input.push_back(line);
    }
    
    return input;
}

bool Day4::checkHorizontal(const int row, const int col) {
    if (puzzle[row][col] == 'X'){
        if (puzzle[row][col + 1] != 'M') return false;
        if (puzzle[row][col + 2] != 'A') return false;
        if (puzzle[row][col + 3] != 'S') return false;
    }
    else if (puzzle[row][col] == 'S') {
        if (puzzle[row][col + 1] != 'A') return false;
        if (puzzle[row][col + 2] != 'M') return false;
        if (puzzle[row][col + 3] != 'X') return false;
    }
    else return false;

    return true;
}

bool Day4::checkVertical(const int row, const int col) {
    if (puzzle[row][col] == 'X'){
        if (puzzle[row + 1][col] != 'M') return false;
        if (puzzle[row + 2][col] != 'A') return false;
        if (puzzle[row + 3][col] != 'S') return false;
    }
    else if (puzzle[row][col] == 'S') {
        if (puzzle[row + 1][col] != 'A') return false;
        if (puzzle[row + 2][col] != 'M') return false;
        if (puzzle[row + 3][col] != 'X') return false;
    }
    else return false;

    return true;
}

bool Day4::checkDiagonalA(const int row, const int col) {
    if (puzzle[row][col] == 'X'){
        if (puzzle[row + 1][col + 1] != 'M') return false;
        if (puzzle[row + 2][col + 2] != 'A') return false;
        if (puzzle[row + 3][col + 3] != 'S') return false;
    }
    else if (puzzle[row][col] == 'S') {
        if (puzzle[row + 1][col + 1] != 'A') return false;
        if (puzzle[row + 2][col + 2] != 'M') return false;
        if (puzzle[row + 3][col + 3] != 'X') return false;
    }
    else return false;

    return true;
}

bool Day4::checkDiagonalB(const int row, const int col) {
    if (puzzle[row][col + 3] == 'X'){
        if (puzzle[row + 1][col + 2] != 'M') return false;
        if (puzzle[row + 2][col + 1] != 'A') return false;
        if (puzzle[row + 3][col]     != 'S') return false;
    }
    else if (puzzle[row][col + 3] == 'S') {
        if (puzzle[row + 1][col + 2] != 'A') return false;
        if (puzzle[row + 2][col + 1] != 'M') return false;
        if (puzzle[row + 3][col]     != 'X') return false;
    }
    else return false;

    return true;
}

void Day4::part1() {
	std::cout << "Part 1" << std::endl;

    int rightness = 0;

    int count = 0;
    
    const int nRows = puzzle.size();
    const int nCols = puzzle[0].size();

    for (int row = 0; row < nRows; row++){
        for (int col = 0; col < nCols; col++){
            const bool colSafe = col < nCols - 3;
            const bool rowSafe = row < nRows - 3;

            if (colSafe) count += checkHorizontal(row, col);
            if (rowSafe) count += checkVertical(row, col);
            if (colSafe && rowSafe){
                count += checkDiagonalA(row, col);
                count += checkDiagonalB(row, col);
            }
        }
    }

    std::cout << "XMAS Count: " << count << std::endl;
}

bool Day4::checkXmas(const int row, const int col) {
    if (puzzle[row + 1][col + 1] != 'A') return false;

    if (puzzle[row][col] == 'M'){
        if (puzzle[row + 2][col + 2] != 'S') return false;
    }
    else if (puzzle[row][col] == 'S'){
        if (puzzle[row + 2][col + 2] != 'M') return false;
    }
    else return false;

    if (puzzle[row][col + 2] == 'M'){
        if (puzzle[row + 2][col] != 'S') return false;
    }
    else if (puzzle[row][col + 2] == 'S'){
        if (puzzle[row + 2][col] != 'M') return false;
    }
    else return false;

    return true;
}

void Day4::part2() {
	std::cout << std::endl << "Part 2" << std::endl;
    
    const int nRows = puzzle.size();
    const int nCols = puzzle[0].size();

    int count = 0;

    for (int row = 0; row < nRows - 2; row++){
        for (int col = 0; col < nCols - 2; col++){
            count += checkXmas(row, col);
        }
    }

    std::cout << "Corrected XMAS Count: " << count << std::endl;
}
