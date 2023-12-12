#include <iostream>
#include <cmath>
#include <chrono>

int solOne(int maximum) {
    int fib_one = 1;
    int fib_two = 2;
    int sum = 2;
    while (fib_one + fib_two < maximum) {
        int fib_temp = fib_one + fib_two;
        if (fib_temp % 2 == 0) {
            sum += fib_temp;
        }
        fib_one = fib_two;
        fib_two = fib_temp;
    }
    return sum;
}

// Uses closed form solution to find invidiual fibonacci numbers, noting that only every third number will be even
int solTwo(int maximum) {
    double golden = 1.6180339887;
    float sum = 0.0;
    int max_index = std::floor( std::log(std::sqrt(5)*(maximum + 0.5)) / std::log(golden)  );
    for (int i=0; i < max_index/3.0 + 1; i++) {
        float fib = std::round( std::pow(golden, (3*i)) / std::sqrt(5) );
        sum += fib;
    }
    return sum;
}

int main()
{
    std::chrono::steady_clock::time_point beginOne = std::chrono::steady_clock::now();
    int sumOne = solOne(4000000);
    std::cout << sumOne;
    std::chrono::steady_clock::time_point endOne = std::chrono::steady_clock::now();
    std::cout << "\nTime to compute: " << std::chrono::duration_cast<std::chrono::microseconds>(endOne - beginOne).count() << "[µs]" << std::endl;

    std::chrono::steady_clock::time_point beginTwo = std::chrono::steady_clock::now();
    int sumTwo = solTwo(4000000);
    std::cout << sumTwo;
    std::chrono::steady_clock::time_point endTwo = std::chrono::steady_clock::now();
    std::cout << "\nTime to compute: " << std::chrono::duration_cast<std::chrono::microseconds>(endTwo - beginTwo).count() << "[µs]" << std::endl;

    return 0;
}
