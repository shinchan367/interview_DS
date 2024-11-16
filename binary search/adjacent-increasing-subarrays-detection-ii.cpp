class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;  // No two subarrays possible if the size is less than 2
        
        // Array to store the length of the longest increasing subsequence starting at each index
        vector<int> isSIncrease(n, 1); 
        
        // Fill the isSIncrease array
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                isSIncrease[i] = isSIncrease[i + 1] + 1;
            }
        }

        int l = 1, r = n / 2, res = 0;
        
        // Binary search for the largest k
        while (l <= r) {
            int mid = l + (r - l) / 2;
            bool check = false;
            
            // Check if two adjacent increasing subarrays of length mid exist
            for (int i = 0; i + 2 * mid <= n; ++i) {
                if (isSIncrease[i] >= mid && isSIncrease[i + mid] >= mid) {
                    check = true;
                    break;
                }
            }

            if (check) {
                res = mid;
                l = mid + 1;  // Try for a larger k
            } else {
                r = mid - 1;  // Try for a smaller k
            }
        }

        return res;
    }
};
