class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el,cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                el=nums[i];
            }
            else if(el==nums[i])cnt++;
            else cnt--;
        }

    int cnt1=0;
    for(int i=0;i<n;i++){
        if(nums[i]==el)cnt1++;
    }
    if(cnt1>(n/2))return el;
    return false;
    }
};
//************************************************************************************************************************
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(ele==0){
                count=nums[i];
            }
          if(count==nums[i]){
              ele++;
          }
          else{
              ele--;
          }
    
        }  
    return count;
    }
};
