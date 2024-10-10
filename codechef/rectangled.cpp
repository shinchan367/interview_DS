#include <iostream>
using namespace std;

// Function to calculate the largest rectangle area
long long largestRectangleArea(int N) {
    if (N < 2) {
        return 0;  
    }
    
    int k = N / 2;  
    long long l, b;

    if (k % 2 == 0) {
        l = b = k / 2;
    } else {
        l = k / 2;
        b = (k / 2) + 1;
    }

    return l * b;  
}

int main() {
    int T;
    cin >> T; 
    while (T--) {
        int N;
        cin >> N;  
        cout << largestRectangleArea(N) << endl;  
    }
    return 0;
}
