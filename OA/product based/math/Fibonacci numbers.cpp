///recursion
#include <iostream>
using namespace std;

// Recursive function to return the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    // Input number of terms
    cout << "Enter the number of terms: ";
    cin >> n;

    // Print the Fibonacci sequence
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}
//dp
#include <iostream>
using namespace std;

int fibonacci(int n, int dp[]) {
    // Base cases
    if (n <= 1) {
        return n;
    }

    // If the value is already calculated, return it
    if (dp[n] != -1) {
        return dp[n];
    }

    // Otherwise, calculate it and store the result
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}

int main() {
    int n;

    // Input number of terms
    cout << "Enter the number of terms: ";
    cin >> n;

    // Create an array to store previously calculated Fibonacci numbers
    int dp[n + 1];

    // Initialize all elements to -1 (indicating uncomputed)
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    // Print the Fibonacci sequence
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i, dp) << " ";
    }

    return 0;
}
