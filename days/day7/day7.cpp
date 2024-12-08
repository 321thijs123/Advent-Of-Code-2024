#include "day7.h"

Day7::Day7(){
	std::cout << " ---- Day 7 ---- " << std::endl;

    const std::string filePath = "../inputs/day7/example.txt";
    readFile(filePath);

	benchmark([this]() {this->part1();});
	benchmark([this]() {this->part2();});
}

void Day7::readFile(const std::string path){
	std::fstream inputFile(path, std::ios_base::in);

    std::string line;

	while (getline(inputFile, line)) {
        std::stringstream ss(line);

        Equation equation;

        ss >> equation.result;

        ss.ignore();

        long long val;

        while(ss>>val){
            equation.params.push_back(val);
        }

        equations.push_back(equation);
    }
}

void Day7::concatInts(long long &a, const long long b) {
    int shift = 10;

    while (b / shift != 0) {
        shift *= 10;
    };

    a = a * shift + b;
}

long long Day7::calculate(const std::vector<long long> &params, const std::vector<Operator> &operators){
    long long total = params[0];

    for (int i = 0; i < operators.size(); i++) {
        switch (operators[i]){
            case add:
                total += params[i + 1];
                break;
            case multiply:
                total *= params[i + 1];
                break;
            case concatenate:
                concatInts(total, params[i + 1]);
                break;
        }
    }

    return total;
}

bool Day7::tryCombinations(const int i, const Equation &equation, std::vector<Operator> &operators) {
    if (i == 0) {
        operators[i] = add;
        if (calculate(equation.params, operators) == equation.result) return true;
        operators[i] = multiply;
        return (calculate(equation.params, operators) == equation.result);
    }
    else {
        operators[i] = add;
        if (tryCombinations(i - 1, equation, operators)) return true;
        operators[i] = multiply;
        if (tryCombinations(i - 1, equation, operators)) return true;

        return false;
    }
}

bool Day7::tryCombinations2(const int i, const Equation &equation, std::vector<Operator> &operators) {
    if (i == 0) {
        operators[i] = add;
        if (calculate(equation.params, operators) == equation.result) return true;
        operators[i] = multiply;
        if (calculate(equation.params, operators) == equation.result) return true;
        operators[i] = concatenate;
        return (calculate(equation.params, operators) == equation.result);
    }
    else {
        operators[i] = add;
        if (tryCombinations2(i - 1, equation, operators)) return true;
        operators[i] = multiply;
        if (tryCombinations2(i - 1, equation, operators)) return true;
        operators[i] = concatenate;
        if (tryCombinations2(i - 1, equation, operators)) return true;

        return false;
    }
}



void Day7::part1() {
	std::cout << "Part 1" << std::endl;

    long long sum = 0;

    for (Equation equation : equations){
        std::vector<Operator> operators(equation.params.size() - 1, add);
        if (tryCombinations(operators.size() - 1, equation, operators))
            sum += equation.result;
    }

    std::cout << "Sum: " << sum << std::endl;
}

void Day7::part2() {
	std::cout << std::endl << "Part 2" << std::endl;

    long long sum = 0;

    for (Equation equation : equations){
        std::vector<Operator> operators(equation.params.size() - 1, add);
        if (tryCombinations2(operators.size() - 1, equation, operators))
            sum += equation.result;
    }

    std::cout << "Sum: " << sum << std::endl;
}
