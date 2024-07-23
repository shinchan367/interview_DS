

class Solution {
public:

    //memoziation
    
    bool mem(int index, int target, vector<int> arr, vector<vector<int>> dp){
        
    if (target==0) return true;
    if (index==0) return (target==arr[index]);

        if (dp[index][target] != -1) return dp[index][target];

        //take case
        bool Take=false;
        if (arr[index]<=target){
            Take=mem(index-1, target-arr[index], arr, dp);
        }

        //not take case        
        bool notTake=mem(index-1, target, arr, dp);
        
        return dp[index][target] = Take||notTake;
    } 
    }
//**************************************************************************************************************

    //Tabulation Solution
class solution{
public:
    bool tab(int n, int k, vector<int> &arr){
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));
        for (int i=0; i<n; i++) dp[i][0]=true;
        if (arr[0]<=k)dp[0][arr[0]]=true;
        for (int index=1; index<n; index++){
            for (int target=1; target<=k; target++){
                bool Take=false;
                if (arr[index]<=target){
                    Take=dp[index-1][target-arr[index]];
                }

                //not take case        
                bool notTake=dp[index-1][target];
                
                dp[index][target] = Take||notTake;
            }
        }return dp[n-1][k];
    }

    bool canPartition(vector<int>& nums) {
        int sum=0, n=nums.size();
        for (int i=0; i<n; i++){
            sum+=nums[i];
        }int k;
        if (sum%2==0){
            k=sum/2;
        }else{
            return false;
        }
        if(n==1){
            return false;
        }
        //vector<vector<int>> dp(n, vector<int>(k+1, -1));
        //return mem(n-1, k, nums, dp);
        return tab(n, k, nums);
      
    }
};
