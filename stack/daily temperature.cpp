//Input: temperatures = [73,74,75,71,69,72,76,73]
//Output: [1,1,4,2,1,1,0,0]
//Example 2:

//Input: temperatures = [30,40,50,60]
//Output: [1,1,1,0]
//Example 3:

//Input: temperatures = [30,60,90]
//Output: [1,1,0]



//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        
        vector<int> result(n);
        
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            
            if(st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i; //days
            }
            
            st.push(i);
        }
        
        return result;
        
    }
};
