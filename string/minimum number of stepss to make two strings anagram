/****************************************************** C++ ******************************************************/
//Approach-1 (Using 2 counters)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        
        int mp_s[26] = {0};
        int mp_t[26] = {0};
        
        for(int i = 0; i<n; i++) {
            mp_s[s[i] - 'a']++;
            mp_t[t[i] - 'a']++;
        }
        
        int result = 0;
        
        for(int i = 0; i < 26; i++) {
            int freq_in_t = mp_t[i];
            
            int freq_in_s = mp_s[i];
            
            if(freq_in_t < freq_in_s) {
                result += freq_in_s - freq_in_t;
            }
        } 
        
        return result;
    }
};


//Approach-2 (Using 1 counter)
//T.C : O(n)
//S.C : O(26) ~ O(1)

#include <iostream>
#include <string>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        int n = s.length();
        int mp[26] = {0};

        // Update frequency based on characters in strings s and t
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }

        int result = 0;

        // Calculate the minimum steps required
        for (int i = 0; i < 26; i++) {
            result += std::max(0, mp[i]);
        } 

        return result;
    }
};

int main() {
    Solution solution;

    // Example usage
    std::string s = "abc";
    std::string t = "def";
    int result = solution.minSteps(s, t);

    // Output the result
    std::cout << "Minimum steps: " << result << std::endl;

    return 0;
}



///using vector

//count_s=[a,b,c]
//count_t=[d,e,f]
//////////////-------------------------------count_s = [1, 1, 1, 0, 0, ..., 0]   // 'a', 'b', 'c' are present
/<<<<<<<<<<<<<<<<<<<<<<<<<<<----------------count_t = [0, 0, 0, 1, 1, ..., 1]   // 'd', 'e', 'f' are present
//<<<<<<<<<<<<<<<<<<<<<<<<<<<----------------steps = |1-0| + |1-0| + |1-0| + |0-1| + |0-1| + |0-1| + ... + |0-0|
 //                                                               = 3 + 3
 //                                                                  = 6
//                                                             result = 6 / 2 = 3


//o(n)  sc:o(1)
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::vector<int> count_s(26, 0);
        std::vector<int> count_t(26, 0);

        // Count the frequency of each character in string s
        for (char ch : s) {
            count_s[ch - 'a']++;
        }

        // Count the frequency of each character in string t
        for (char ch : t) {
            count_t[ch - 'a']++;
        }

        // Calculate the minimum steps required
        int steps = 0;
        for (int i = 0; i < 26; i++) {
            steps += std::abs(count_s[i] - count_t[i]);
        }

        // Return half of the total steps (as each step involves two characters)
        return steps / 2;  
    }
};

int main() {
    Solution solution;

    // Example usage
    std::string s = "abc";
    std::string t = "def";
    int result = solution.minSteps(s, t);

    // Output the result
    std::cout << "Minimum steps: " << result << std::endl;

    return 0;
}
