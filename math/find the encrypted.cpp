class Solution {
public:
    string getEncryptedString(string s, int k) {
        string result;
        int n = s.size();
        for(int i = 0; i < n; i++){
            result += s[(i + k) % n]; // using modulo to ensure index stays within bounds
        }
        return result;
    }
};
