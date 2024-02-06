//Approach-1 (Using Sorting)
//T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto str:strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        
        vector<vector<string>> result;
        for(auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};


//Approach-2
//T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
public:
    
    string generate(string &s) {
        int count[26] = {0};
        
        for(char &ch : s) {
            count[ch-'a']++;
        }
        
        string new_s;
        
        for(int i = 0; i<26; i++) {
            
            if(count[i] > 0) {
                new_s += string(count[i], i+'a');
            }
        }
        
        return new_s;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string &s : strs) {
            string new_s = generate(s);
            
            mp[new_s].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto &it : mp) {
            result.push_back(std::move(it.second));
        }
        
        return result;
        
    }
};
