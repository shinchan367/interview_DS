#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

// Function to perform the vowel conversions
std::string convertVowels(const std::string& word) {
    // Vowel conversion map
    std::unordered_map<char, char> vowelMap = {
        {'A', 'E'}, {'E', 'I'}, {'I', 'O'}, {'O', 'U'}, {'U', 'A'}
    };
    
    std::string result = word;
    
    // Convert vowels based on the map
    for (char& ch : result) {
        // Convert if the character is a vowel
        if (vowelMap.find(ch) != vowelMap.end()) {
            ch = vowelMap[ch]; // Replace the vowel
        }
    }
    
    return result;
}

int main() {
    // Input word
    std::string word1 = "APPLE";
    
    // Step 1: Convert vowels
    std::string convertedWord = convertVowels(word1);
    
    // Step 2: Reverse the converted word
    std::reverse(convertedWord.begin(), convertedWord.end());
    
    // Output the final result
    std::cout << "Final result: " << convertedWord << std::endl;

    return 0;
}
