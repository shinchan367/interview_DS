class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> nextGreater;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            if (nextGreater.find(nums1[i]) != nextGreater.end()) {
                result[i] = nextGreater[nums1[i]];
            }
        }
        
        return result;
    }
};
