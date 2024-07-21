class Solution {
public:
    int maxOperations(string s) {
       int n = s.length();
        int cnt = 0;   int ans = 0;  
        for(int i = 0; i < n; i++) {
            if (s[i] == '0') {
                 ans += cnt;
            while(i<n && s[i]=='0'){
                i++;
            }
            }
            cnt++;
        }
        
        return ans;
    }
    
};
