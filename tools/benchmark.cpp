#include "benchmark.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

void benchmark(const std::function<void()>& function) {
    high_resolution_clock::time_point start = high_resolution_clock::now();

    function();

    high_resolution_clock::time_point end = high_resolution_clock::now();

    microseconds duration = duration_cast<microseconds>(end - start);
    
    std::cout << "time: " << duration.count() << " microseconds\n";
}
