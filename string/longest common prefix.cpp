#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string newstr, str = strs[0];

    // Traversing all the strings of strs.
    for(int i = 1; i < strs.size(); i++){
        // Traversing all the characters of the string str.
        for(int j = 0; j < str.size() && j < strs[i].size(); j++){
            if(str[j] == strs[i][j]){
                newstr += str[j];
            }
            else{
                // If j is 0 means, even the first element is not matching. So return "".
                if(j == 0) return "";
                break;
            }
        }
        str = newstr;
        newstr = "";
    }
    return str;
}

//2 Approach  sort


std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string result = "";

    // Sort the vector
    std::sort(strs.begin(), strs.end());

    // Get the first and last strings
    std::string first = strs[0];
    std::string last = strs[strs.size() - 1];

    // Start comparing
    for (int i = 0; i < first.length(); i++) {
        if (first[i] != last[i])
            break;
        result += first[i];
    }

    return result;
}
