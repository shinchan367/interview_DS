//leetcode 560
//Input: nums = [1,1,1], k = 2
//Output: 2


//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int sum = 0;
        map<int, int> mp;
        mp.insert({0,1});
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            
            if(mp.count(sum-k))
                result += mp[sum-k];
            
            mp[sum]++;
        }
        return result;
    }
};
