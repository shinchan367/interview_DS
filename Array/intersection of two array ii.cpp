/*⏰ Time complexity: O(n), since we go through each element in nums1 and nums2 once
🧺 Space complexity: O(1), since we use to arrays of constant size 1001 and not counting res array in extra space
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int ind1 = 0, ind2 = 0;
        int l1 = nums1.size(), l2 = nums2.size();
        vector<int> res;

        while (ind1 < l1 && ind2 < l2) {
            int n1 = nums1[ind1];
            int n2 = nums2[ind2];
            if (n1 == n2) {
                res.push_back(n1);
                ind1++;
                ind2++;
            } else if (n1 > n2) {
                ind2++;
            } else {
                ind1++;
            }
        }

        return res;
    }
};
//*******************************************************************************************************************************
/*⏰ Time complexity: O(n*log n), since we use sorting (in some languages this time complexity can be changed)
🧺 Space complexity: O(n), not because we define res array but because sorting usually takes some extra space*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> counting1(1001, 0);
        vector<int> counting2(1001, 0);
        
        for (int n : nums1) {
            counting1[n]++;
        }
        
        for (int n : nums2) {
            counting2[n]++;
        }
        
        vector<int> res;
        for (int number = 0; number < 1001; ++number) {
            int mn = min(counting1[number], counting2[number]);
            for (int i = 0; i < mn; ++i) {
                res.push_back(number);
            }
        }
        
        return res;
    }
};
