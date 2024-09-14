#include <iostream>
using namespace std;

int reverseNumber(int num) {
    int reversed = 0;
    
    while (num != 0) {
        int digit = num % 10;  // Get the last digit
        reversed = reversed * 10 + digit;  // Append it to reversed number
        num /= 10;  // Remove the last digit from num
    }

    return reversed;
}

int main() {
    int num;
    
    cout << "Enter a number: ";
    cin >> num;

    int reversed = reverseNumber(num);
    
    cout << "Reversed number: " << reversed << endl;
    
    return 0;
}

