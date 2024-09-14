#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int stringchange(string &str1, string &str2) {
    int cost = 0; // Initialize cost
    unordered_map<char, int> mp;
    
    // Step 1: Build frequency map for str2
    for (char c : str2) {
        mp[c]++;
    }

    // Step 2: Iterate over str1
    for (char c : str1) {
        if (mp.find(c) != mp.end()) {
            // Character exists in both strings, no cost for swap
            mp[c]--;  // Decrement the frequency in the map
            if (mp[c] == 0) {
                mp.erase(c); // Remove if frequency becomes zero
            }
        } 
       

    return cost;
}
}

int main() {
    string str1 = "abd";
    string str2 = "aabccad";
    
    int result = stringchange(str1, str2);
    
    cout << "Cost to change str1 to str2: " << result << endl;
    
    return 0;
}
