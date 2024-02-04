//Input: nums = [3,3,3]
//Output: "equilateral"
//Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
class Solution {
public:
    string triangleType(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		if(nums[0]+nums[1]<=nums[2]) {
			return "none";
		}
		
		if(nums[0]==nums[2]) {
			return "equilateral";
		}
		if(nums[0]==nums[1]||nums[1]==nums[2]) {
			return "isosceles";
		}
		return "scalene";
    }
};
