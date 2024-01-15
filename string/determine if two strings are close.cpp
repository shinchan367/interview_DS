//problem statement:
//Input: word1 = "abc", word2 = "bca"
//Output: true
//Explanation: You can attain word2 from word1 in 2 operations.
//Apply Operation 1: "abc" -> "acb"
//Apply Operation 1: "acb" -> "bca"

//T.C : O(n)
//S.C : O(26) ~ O(1)


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        if (m != n) {
            return false;
        }
        
        vector<int> freq1(26);
        vector<int> freq2(26);
        
        for (int i = 0; i < n; i++) {
            char ch1 = word1[i];
            char ch2 = word2[i];
            
            freq1[ch1 - 'a']++;
            freq2[ch2 - 'a']++;
        }
        // checking alphabets in both
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] != 0 && freq2[i] == 0) || (freq1[i] == 0 && freq2[i] != 0)) {
                return false;
            }
        }
        //pont 2
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        return freq1 == freq2;
    }
};


