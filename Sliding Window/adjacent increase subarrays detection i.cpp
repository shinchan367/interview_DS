class Solution {
public:

bool isStrictlyIncreasing(const vector<int>& nums, int start, int k) {
    for (int i = start; i < start + k - 1; i++) {
        if (nums[i] >= nums[i + 1]) return false;
    }
    return true;
}

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
         int n = nums.size();
    if (n < 2 * k) return false; 

    for (int i = 0; i <= n - 2 * k; i++) {
        if (isStrictlyIncreasing(nums, i, k) && isStrictlyIncreasing(nums, i + k, k)) {
            return true;
        }
    }

    return false;
    }
};
  /*
  Intuition
To determine if there are two adjacent subarrays of length k that are both strictly increasing, we need to check pairs of subarrays in the array. Specifically, we will look for two subarrays that start at different indices but are right next to each other. If both subarrays are strictly increasing, we can return true; otherwise, we return false.

Approach
Define a helper function, isStrictlyIncreasing, to check if a subarray of length k is strictly increasing.

Loop through the array up to n - 2 * k (ensuring room for two adjacent subarrays).

For each possible starting point i, check if both the subarray starting at i and the one starting at i + k are strictly increasing.

If both conditions are met, return true. If no such pair is found, return false.

DRY RUN TABLE
NUMS= [2,5,7,8,9,2,3,4,3,1] K =3

Screenshot 2024-11-10 at 9.24.19 AM.png

Complexity
Time complexity:
O(n×k), as we may check up to n−2k possible starting indices and each check requires O(k) operations.

Space complexity:
O(1), since only a few variables are used


*/

