//Example 1:

//Input: nums = [1,2,2,3,1,4]
//Output: 4
//Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
//So the number of elements in the array with maximum frequency is 4.
//Example 2:

//Input: nums = [1,2,3,4,5]
//Output: 5
//Explanation: All elements of the array have a frequency of 1 which is the maximum.
//So the number of elements in the array with maximum frequency is 5.




class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int it:nums)
            map[it]++;
        
        int maxi=INT_MIN;
        for(auto it:map)
        {
            if(it.second>maxi)
                maxi=it.second;
        }
        int ans=0;
        for(auto it:map)
        {
            if(it.second ==maxi)
                ans+=maxi;
        }

        return ans;
    }
};
