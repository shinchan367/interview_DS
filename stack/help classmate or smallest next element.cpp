class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
    stack<int>st;
    vector<int>nse(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            nse[st.top()]=arr[i];
            st.pop();
        }
        st.push(arr[i]);
    }
    return nse;
    } 
};
