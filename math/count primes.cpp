class Solution {
public:
    int countPrimes(int n) {
         if (n <= 1)
            return 0;

        vector<int> prime(n, 1); // Initialize all elements to 1 (considered prime)
        prime[0] = prime[1] = 0; // Set 0 and 1 as non-prime

        for (int i = 2; i <=sqrt(n); ++i) {
            if (prime[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0; // Mark multiples of i as non-prime
                }
            }
        }
        
        return accumulate(prime.begin(), prime.end(), 0); // Count the number of primes
 
    }
};
