/////Time Complexity: 
𝑂(𝑛𝑚)
// where n is the number of elements in nums and 𝑚
//m is the maximum number in nums.
//Space Complexity: 𝑂(1)

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
         int totalSum = 0;
        for (int num : nums) {
            int divisorsCount = 0;
            int divisorSum = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    divisorsCount++;
                    divisorSum += i;
                    if (i * i != num) {
                        divisorsCount++;
                        divisorSum += num / i;
                    }
                    if (divisorsCount > 4) {
                        break;
                    }
                }
            }
            if (divisorsCount == 4) {
                totalSum += divisorSum;
            }
        }
        return totalSum;
    
    }
};
//*************************************************************************************************************************************8
//Time Complexity: 𝑂(𝑛loglog𝑛+𝑁𝑀)
//Space Complexty: o(n)
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        const int MAX_LIMIT = 100000;
        
        // Generate prime numbers up to MAX_LIMIT
        vector<bool> isPrime = sieveOfEratosthenes(MAX_LIMIT);
        
        // Initialize the total sum
        int totalSum = 0;
        
        // Iterate over each number in the input vector
        for (int num : nums) {
            int divisorsCount = 0;
            int divisorSum = 0;
            
            // Iterate up to the square root of the number to find divisors
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    divisorsCount++;
                    divisorSum += i;
                    
                    // Add the other divisor if it's not the same as the first one
                    if (i * i != num) {
                        divisorsCount++;
                        divisorSum += num / i;
                    }
                    
                    // If there are more than 4 divisors, exit the loop
                    if (divisorsCount > 4) {
                        break;
                    }
                }
            }
            
            // If the number has exactly 4 divisors, add the sum to the total sum
            if (divisorsCount == 4) {
                totalSum += divisorSum;
            }
        }
        
        return totalSum;
    }
    
private:
    vector<bool> sieveOfEratosthenes(int n) {
        // Initialize a vector to store prime flags
        vector<bool> isPrime(n + 1, true);
        
        // Set 0 and 1 as non-prime
        isPrime[0] = isPrime[1] = false;
        
        // Apply Sieve of Eratosthenes algorithm
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        return isPrime;
    
    }
};
