lass Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n=nums.size();
        int single=0;
        int doubl=0;
        for(int i=0;i<n;i++){
              if(nums[i]<10){
                single+=nums[i];
              }
              else{
                doubl+=nums[i];
              }
        }
        if(single==doubl){
            return false;
        }
        return true;
    }
};
