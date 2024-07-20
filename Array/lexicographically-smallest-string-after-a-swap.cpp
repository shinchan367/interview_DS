class Solution {
public:
    std::string getSmallestString(std::string s) {
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
           
            if ((s[i] % 2 == 0 && s[i + 1] % 2 == 0) || (s[i] % 2 != 0 && s[i + 1] % 2 != 0)) {
                if (s[i] > s[i + 1]) {
                    std::swap(s[i], s[i + 1]);
                    break;
                }
            }
        }
        return s;
    }
};
