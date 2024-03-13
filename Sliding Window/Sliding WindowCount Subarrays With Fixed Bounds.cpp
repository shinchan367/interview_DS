//Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
//Output: 2
//Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
//Example 2:

//Input: nums = [1,1,1,1], minK = 1, maxK = 1
//Output: 10
//Explanation: Every subarray of nums is a fixed-bound subarray. T



//Approach-1 (Brute Force)
//Find all subarrays and check if min is minK and max is maxK
//Code will be provided soon for brute force

//Approach-2 (Optimal O(n)) - Sliding Window
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        
        int minPosition = -1;
        int maxPosition = -1;
        int leftBound   = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            if(nums[i] == minK)
                minPosition = i;
            if(nums[i] == maxK)
                maxPosition = i;
            
            int count = min(maxPosition, minPosition) - leftBound;
            
            ans += (count <= 0) ? 0 : count;
            
        }
        
        return ans;
    }
};
