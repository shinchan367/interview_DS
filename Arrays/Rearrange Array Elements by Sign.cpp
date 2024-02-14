class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int p=0;
        int n1=1;
        vector<int>result(n);
        for(auto &num:nums){
            if(num>0){
                result[p]=num;
                p+=2;
            }
            else{
                result[n1]=num;
                n1+=2;
            }
        }
        return result;
    }
};
