#include <iostream>
#include <cmath>
#include <chrono>

// Functions need to come before main() to be recognized
int solOne() {
    int max = 1000;
    int sum = 0;
    for (int i = 0; i<max; i++) {
        if (i % 3 == 0) {
            sum += i;
        }    
        else if (i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

double summation(double num, double max) {
    double floor(double x); // function within a function
    double fl = floor(max/num);
    return num * fl * (fl + 1) / 2.0;
}

// Uses closed form formula to compute sum, adjusted by what multiples needed
int solTwo() {
    return summation(3,999) + summation(5,999) - summation(15,999);
}

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int sum = solOne();
    std::cout << sum;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\nTime to compute: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    std::chrono::steady_clock::time_point beginTwo = std::chrono::steady_clock::now();
    int sumTwo = solTwo();
    std::cout << sumTwo;
    std::chrono::steady_clock::time_point endTwo = std::chrono::steady_clock::now();
    std::cout << "\nTime to compute: " << std::chrono::duration_cast<std::chrono::microseconds>(endTwo - beginTwo).count() << "[µs]" << std::endl;
    return 0;
}

