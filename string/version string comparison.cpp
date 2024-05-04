//Approach (Using stringstream tokenizer in C++)
//T.C : O(m+n)
//S.C : O(m+n)

class Solution {
public:
    // Function to split version string into tokens separated by '.'
    vector<string> getTokens(string version) {
        stringstream v(version); // Creating a stringstream object 'v' with input string 'version'
        string token_v = ""; // Declaring an empty string 'token_v' to store each token
        vector<string> version_tokens; // Declaring an empty vector to store version tokens
        
        // Loop to extract tokens from the stringstream
        while(getline(v, token_v, '.')) { // Using getline to extract tokens from stringstream 'v' separated by '.'
            version_tokens.push_back(token_v); // Pushing each token into the vector
        }
        return version_tokens; // Returning the vector of version tokens
    }
    
    // Function to compare two version strings
    int compareVersion(string version1, string version2) {
        // Getting tokens for both versions
        vector<string> v1 = getTokens(version1); // Tokens of version1
        vector<string> v2 = getTokens(version2); // Tokens of version2
        
        // Getting sizes of both token vectors
        int m = v1.size(); // Size of version1 tokens
        int n = v2.size(); // Size of version2 tokens
        
        // Initializing loop variable
        int i = 0;
        
        // Comparing versions token by token
        while(i < m || i < n) { // Loop until both token vectors are exhausted
            // Converting tokens to integers for comparison, using 0 if tokens are exhausted
            int a = i < m ? stoi(v1[i]) : 0; // Converting token to integer if available, otherwise 0
            int b = i < n ? stoi(v2[i]) : 0; // Converting token to integer if available, otherwise 0
            
            // Comparing tokens
            if(a > b) // If token from version1 is greater
                return 1; // Return 1 (indicating version1 is greater)
            else if(b > a) // If token from version2 is greater
                return -1; // Return -1 (indicating version2 is greater)
            else // If tokens are equal
                i++; // Move to the next token
        }
        return 0; // If no difference found, versions are equal, return 0
    }
};
