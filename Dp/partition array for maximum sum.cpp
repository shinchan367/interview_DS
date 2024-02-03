//https://leetcode.com/problems/partition-array-for-maximum-sum/solutions/4668709/tle-to-o-n-k-plain-recursion-tabulation-explained/
///////////////////////////////////////////recursion/////////////////////////////////////////////

//Time complexity: O(n^k)
//Space complexity: O(n)
class Solution {
public:
    int solve(vector<int> &arr, int k, int ind){
        int n = arr.size();
        if(ind >= n) return 0;

        int mx = 0, ans = 0;
        for(int i=ind; i<min(ind+k, n); i++){
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1)*mx + solve(arr, k, i+1));
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return solve(arr, k, 0);
    }
};
/////////////////////////////////////////////////Recursion + Memoization//////////////////////////////////////////
//Time complexity: O(n*k)
//Space complexity: O(n)
class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &arr, int k, int ind){
        int n = arr.size(), mx = 0, ans = 0;
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        for(int i=ind; i<min(ind+k, n); i++){
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1)*mx + solve(arr, k, i+1));
        }
        dp[ind] = ans;
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(), -1);
        return solve(arr, k, 0);
    }
};

/////////////////////////////////////////////Tabulation//////////////////////////////////////////////////////////////
//Time complexity: O(n*k)
//Space complexity: O(n)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        int sub_ans = 0, mx = 0;
        for(int i=n-1; i>=0; i--){
            mx = arr[i];
            sub_ans = 0;
            for(int j=i; j<min(i+k, n); j++){
                mx = max(mx, arr[j]);
                sub_ans = max(sub_ans, (j - i + 1)*mx + dp[j+1]);
            }
            dp[i] = sub_ans;
        }
        return dp[0];
    }
};
