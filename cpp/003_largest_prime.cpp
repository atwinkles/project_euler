#include <iostream>
#include <cmath>
#include <chrono>

int solOne(long value) {
    int maximum = 0;
    long i = value;
    for (int j=2;j<std::floor(std::sqrt(value));j++) {
        while ( i % j == 0 ) {
            i = i / j;
            if ( j > maximum ) {
                maximum = j;
            }
        }
        
    }
    return maximum;
}

// Uses a Sieve of Eratosthenes to compute primes, for fun
int solTwo(long value) {
    long max = std::sqrt(value);
    int solution = 0;
    std::vector<bool> sieve(value-1, true);
    for ( int i = 2; i <= max; i++ ) {
        if ( sieve[i-2] ) {
            if ( value % i == 0 && i > solution ) {
                solution = i;
            }
            for (int j = i*i; j <= value; j += i) {
                sieve[j-2] = false;
            }
        }
    }
    return solution;
}

int main()
{
    std::chrono::steady_clock::time_point beginOne = std::chrono::steady_clock::now();
    long sumOne = solOne(600851475143);
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
