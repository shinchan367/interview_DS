//Example 1:

//Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
//Output: [[1,1,3],[3,4,5],[7,8,9]]
//Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
//The difference between any two elements in each array is less than or equal to 2.
//Note that the order of elements is not important.

//T.C : O(nlogn)
//S.C : O(1)

class solution{

public:
 vector<vector<int>> divideArray(vector<int>& nums, int k) {
   int n=nums.size();
    vector<vector<int>>result;
     sort(nums.begin(),nums.end());
    for(int i=0;i<n;i+=3){
       if(nums[i+2]-nums[i]>k{
         return {};
    }
    result.push_back({nums[i],nums[i+1],nums[i+2]});
 }
return result;
}
};
