
class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n, -1); // Initialize the result vector with -1
        stack<int> st; // Stack to keep track of the next greater elements
        
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack while the stack is not empty and
            // the top of the stack is less than or equal to the current element
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            
            // If the stack is not empty, the next greater element for nums[i] is at the top of the stack
            if (!st.empty()) {
                nge[i] = st.top();
            }
            
            // Push the current element onto the stack
            st.push(nums[i]);
        }
        
        return nge;
    }
};


//circular
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n,-1);
        for(int i=2*n-1;i>=0;i--){
          while(!st.empty() && st.top()<=nums[i%n]){
            st.pop();
          }
          if(i<n){
            if(!st.empty())
            nge[i]=st.top();
          }
          st.push(nums[i%n]);
        }
        return nge;
    }
};
