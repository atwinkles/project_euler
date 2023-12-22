#include <iostream>
#include <cmath>
#include <chrono>

bool isPrime(int num) {
    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    for(int i=3; (i*i)<=num; i+=2){
        if(num % i == 0 ) return false;
    }
    return true;
}

int solOne(long value) {
    int total = 0;
    for ( int i = 2; i < value; i++ ) {
        if (isPrime(i)) {
            // convert to binary
            // rotate number
        }
    }
    return 0;
}

int solTwo(long value) {
    return 0;
}

int main()
{
    std::chrono::steady_clock::time_point beginOne = std::chrono::steady_clock::now();
    int sumOne = solOne(100);
    std::cout << sumOne;
    std::chrono::steady_clock::time_point endOne = std::chrono::steady_clock::now();
    std::cout << "\nTime to compute: " << std::chrono::duration_cast<std::chrono::microseconds>(endOne - beginOne).count() << "[µs]" << std::endl;

    //std::chrono::steady_clock::time_point beginTwo = std::chrono::steady_clock::now();
    //int sumTwo = solTwo(600851475143);
    //std::cout << sumTwo;
    //std::chrono::steady_clock::time_point endTwo = std::chrono::steady_clock::now();
    //std::cout << "\nTime to compute: " << std::chrono::duration_cast<std::chrono::microseconds>(endTwo - beginTwo).count() << "[µs]" << std::endl;

    return 0;
}
