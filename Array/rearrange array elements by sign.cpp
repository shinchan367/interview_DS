class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positive=0;
        int negative=1;
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
              if(nums[i]<0){
                res[negative]=nums[i];
                negative+=2;
              }
              else{
                res[positive]=nums[i];
                positive+=2;
              }
        }
        return res;
    }
};
