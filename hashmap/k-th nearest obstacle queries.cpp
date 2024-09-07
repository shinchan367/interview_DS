class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int>result;
        priority_queue<int>maxheap;
        for(auto &q:queries){
            int a=q[0];
            int b=q[1];
            int d=abs(a)+abs(b);
            if(maxheap.size()<k){
               maxheap.push(d);
            }
            else if(d<maxheap.top()){
                maxheap.pop();
                maxheap.push(d);
            }

            if(maxheap.size()<k){
                result.push_back(-1);
            }
            else{
                result.push_back(maxheap.top());
            }
        }
        return result;
    }
};
