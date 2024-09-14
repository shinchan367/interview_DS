#include <iostream>
#include <string>

// Function to count non-space characters in a string
int countCharacters(const std::string &str) {
    int count = 0;
    
    for (char ch : str) {
        if (ch != ' ') {  // Check if character is not a space
            count++;
        }
    }
    
    return count;
}

int main() {
    std::string str = "hello world";
    
    // Call the function to get the count of non-space characters
    int charCount = countCharacters(str);
    
    std::cout << "The total number of characters in the string (excluding spaces) \"" << str << "\" is: " << charCount << std::endl;
    
    return 0;
}
