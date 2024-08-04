//Approach 1: Brute Force
//Time complexity: O(n^2 ⋅logn)
//space complexity: O(n2)

We create a storeSubarray a
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> storeSubarray;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            // Iterate through all indices ahead of the current index.
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                storeSubarray.push_back(sum);
            }
        }
        // Sort all subarray sum values in increasing order.
        sort(storeSubarray.begin(), storeSubarray.end());

        // Find the sum of all values between left and right.
        int rangeSum = 0, mod = 1e9 + 7;
        for (int i = left - 1; i <= right - 1; i++) {
            rangeSum = (rangeSum + storeSubarray[i]) % mod;
        }
        return rangeSum;
    }
};
//Approach 2: Priority Queue
//Time complexity: O(n2⋅logn)
//Space complexity: O(n)
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});

        int ans = 0, mod = 1e9 + 7;
        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();
            // If the current index is greater than or equal to left, add the
            // value to the answer.
            if (i >= left) ans = (ans + p.first) % mod;
            // If index is less than the last index, increment it and add its
            // value to the first pair value.
            if (p.second < n - 1) {
                p.first += nums[++p.second];
                pq.push(p);
            }
        }
        return ans;
    }
};
//Approach 3: Binary Search and Sliding Window
//Time complexity: O(nlogsum)
//Space complexity: O(1)
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long result =
            (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) %
            mod;
        // Ensure non-negative result
        return (result + mod) % mod;
    }

private:
    int mod = 1e9 + 7;
    // Helper function to count subarrays with sum <= target and their total
    // sum.
    pair<int, long long> countAndSum(vector<int>& nums, int n, int target) {
        int count = 0;
        long long currentSum = 0, totalSum = 0, windowSum = 0;
        for (int j = 0, i = 0; j < n; ++j) {
            currentSum += nums[j];
            windowSum += nums[j] * (j - i + 1);
            while (currentSum > target) {
                windowSum -= currentSum;
                currentSum -= nums[i++];
            }
            count += j - i + 1;
            totalSum += windowSum;
        }
        return {count, totalSum};
    }

    // Helper function to find the sum of the first k smallest subarray sums.
    long long sumOfFirstK(vector<int>& nums, int n, int k) {
        int minSum = *min_element(nums.begin(), nums.end());
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int left = minSum, right = maxSum;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countAndSum(nums, n, mid).first >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        auto [count, sum] = countAndSum(nums, n, left);
        // There can be more subarrays with the same sum of left.
        return sum - left * (count - k);
    }
};
