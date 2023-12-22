#include <iostream>
#include <cmath>
#include <chrono>

int divSum(int num) {
    int sum = 0;
    for ( int i = 0; i < num; i++ ) {
        if ( num % i == 0 ) {
            sum += i;
        }
    }
    return sum;
}

int solOne(long value) {
    std::vector<bool> amicables(value-1,true);
    int sum = 0;
    for ( int i = 0; i < value - 1; i++ ) {
        if ( amicables[i] ) {
            //std::cout << "---" << std::endl;
            int divSumValue = divSum( i + 1 );
            int reverseDivSumValue = divSum(divSumValue);
            //std::cout << i + 1 << ", " << divSumValue << ", " << reverseDivSumValue << std::endl;
            if ( reverseDivSumValue != i + 1 ) {
                amicables[i] = false;
                amicables[reverseDivSumValue] = false;
            }
            if ( divSumValue == i + 1 ) {
                amicables[i] = false;
            }
        }
        if ( amicables[i] ) {
            sum += i + 1;
            //std::cout << i + 1 << " -> " << divSum(i + 1) << std::endl;
        }
    }
    return sum;
}

int main()
{
    std::chrono::steady_clock::time_point beginOne = std::chrono::steady_clock::now();
    int sumOne = solOne(10000);
    //int sumOne = divSum(220);
    std::cout << sumOne;
    std::chrono::steady_clock::time_point endOne = std::chrono::steady_clock::now();
    std::cout << "\nTime to compute: " << std::chrono::duration_cast<std::chrono::microseconds>(endOne - beginOne).count() << "[µs]" << std::endl;

    //std::chrono::steady_clock::time_point beginTwo = std::chrono::steady_clock::now();
    //int sumTwo = solTwo(10000);
    //std::cout << sumTwo;
    //std::chrono::steady_clock::time_point endTwo = std::chrono::steady_clock::now();
    //std::cout << "\nTime to compute: " << std::chrono::duration_cast<std::chrono::microseconds>(endTwo - beginTwo).count() << "[µs]" << std::endl;

    return 0;
}
