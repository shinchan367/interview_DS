class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
       const int MOD = 1e9 + 7;
        vector<int> ans(n, 1);
        
        for (int i = 0; i < k; ++i) {
            vector<int> newAns(n, 0);
            newAns[0] = ans[0];
            for (int j = 1; j < n; ++j) {
                newAns[j] = (newAns[j - 1] + ans[j]) % MOD;
            }
            ans = newAns;
        }
        
        return ans[n - 1];
    }
};
