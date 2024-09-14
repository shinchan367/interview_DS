#include <iostream>
#include <vector>

std::vector<bool> isprime;

void sieve(int rangeLeft, int rangeRight) {
    // Ensure that rangeRight is at least 2
    if (rangeRight < 2) {
        std::cout << "No primes in the specified range." << std::endl;
        return;
    }

    // Adjust rangeLeft to be at least 2 because prime numbers start from 2
    rangeLeft = std::max(2, rangeLeft);
    
    isprime.assign(rangeRight + 1, true);  // Initialize the isprime vector
    isprime[0] = isprime[1] = false;       // 0 and 1 are not primes

    // Sieve of Eratosthenes to mark non-prime numbers
    for (int i = 2; i * i <= rangeRight; ++i) {
        if (isprime[i]) {
            for (int j = i * i; j <= rangeRight; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int main() {
    int rangeLeft = -10;  // Set the lower bound (can be negative)
    int rangeRight = 50;  // Set the upper bound
    
    sieve(rangeLeft, rangeRight);  // Run the sieve for the range

    // Output the prime numbers in the range [rangeLeft, rangeRight]
    std::cout << "Prime numbers between " << rangeLeft << " and " << rangeRight << ":\n";
    for (int i = rangeLeft; i <= rangeRight; ++i) {
        if (i >= 2 && isprime[i]) {  // Ensure only numbers >= 2 are printed
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
