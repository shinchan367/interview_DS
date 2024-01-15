/*n = 2
total = 10
cost = [10, 9]
Output: 2
Explanation: 
Geek can buy the first course for 10 amount, 
complete it on the same date and redeem 9 back. 
Next, he can buy and complete the 2nd course too.*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Recursion>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Time Complexity: O(2N), As we are considering all the possible combinations using recursion.
//Space Complexity: O(N), As the size of the recursive call stack would be N.

class Solution {
    int solve(int i, int j, vector<int>& cost)
    {
        if (i == cost.size())
            return 0;

        int ans = solve(i + 1, j, cost);
        if (j >= cost[i]) {
            ans = max(
                ans, 1
                         + solve(i + 1,
                                 j - cost[i]
                                     + ((9 * cost[i]) / 10),
                                 cost));
        }

        return ans;
    }

public:
    int max_courses(int n, int total, vector<int>& cost)
    {
        return solve(0, total, cost);
    }
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<memoization>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//Time Complexity: O(N*total), As we are only visiting for N*total different states.
//Space Complexity: O(N*total), As we have made a dp array of size N*(tot
class Solution{
    int dpf(int i, int j, vector<vector<int> > &dp, vector<int> &cost)
    {
        if(i==dp.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j] = dpf(i+1,j,dp,cost);
        if(j >= cost[i])
        {
            dp[i][j] = max(dp[i][j], 1 + dpf(i+1, j - cost[i] + ((9*cost[i])/10), dp, cost));
        }
        return dp[i][j];
    }
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int> > dp(n,vector<int>(total+1,-1));
        return dpf(0,total,dp,cost);
    }
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DPPPPPPPP>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Complexity:
//Time Complexity: O(N*total), As we are running a loop of size N*total.
//Space Complexity: O(N*total), As we have made a dp array of size (N+1)*(total+1).


class Solution {

public:
    int max_courses(int n, int total, vector<int>& cost)
    {
        vector<vector<int> > dp(n + 1,
                                vector<int>(total + 1, -1));

        for (int i = n; i >= 0; i--) {
            for (int j = 0; j <= total; j++) {

                if (i == n) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i + 1][j];

                    if (j >= cost[i]) {
                        dp[i][j] = max(
                            dp[i][j],
                            1
                                + dp[i + 1][j - cost[i]
                                            + ((9 * cost[i])
                                               / 10)]);
                    }
                }
            }
        }

        return dp[0][total];
    }
};
