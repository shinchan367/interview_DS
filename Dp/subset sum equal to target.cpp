class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
       std::vector<std::vector<bool>> t(n + 1, std::vector<bool>(sum + 1));
 for (int i = 0; i <= n; i++) {
        t[i][0] = true;
    }

    // Initialize first row, except t[0][0], to false (non-zero sum cannot be achieved with zero elements)
    for (int i = 1; i <= sum; i++) {
        t[0][i] = false;
    }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] ||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};
