class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected=heights;
         sort(heights.begin(),heights.end());
       int n=heights.size();
       int result=0;
    for(int i=0;i<n;i++){
        if(heights[i]!=expected[i]){
                 result+=1;
        }

    }
    return result;
    }
}; 
