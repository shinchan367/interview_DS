class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        // Declaration to count odd, even and both pairs.
        // In both pairs: 1st odd, 2nd even, 3rd odd, ...
        // To count if pair (sub[i] + sub[i + 1]) % 2 for if all elements are odd, even, or both
        int c = nums[0] % 2, odd = 0, even = 0, both = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                even++;
            } else {
                odd++;
            }
            //{even,odd,even,odd....}
            if (num % 2 == c) {
                both++;
                c = 1 - c;  // Toggle the parity
            }
        }
        return max(both,max(even, odd));
    }
};
