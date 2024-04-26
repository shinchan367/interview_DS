class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
{
        // Your code here
        int n=heights.size();
        vector<long long> lt,rt;
        stack<pair<int,int>> stk1,stk2;
        for(int i=0;i<n;i++)
        {
            if(stk1.empty())
            lt.push_back(-1);
            else
            {
                while(!stk1.empty() && stk1.top().first>=heights[i])
                stk1.pop();
                if(stk1.empty())
                lt.push_back(-1);
                else
                lt.push_back(stk1.top().second);
            }
            stk1.push({heights[i],i});
        }
    
        for(int i=n-1;i>=0;i--)
        {
            if(stk2.empty())
            rt.push_back(n);
            else
            {
                while(!stk2.empty() && stk2.top().first>=heights[i])
                stk2.pop();
                if(stk2.empty())
                rt.push_back(n);
                else
                rt.push_back(stk2.top().second);
            }
            stk2.push({heights[i],i});
        }
        reverse(rt.begin(),rt.end());
        
        for(int i=0;i<n;i++)
        {
            rt[i]=(rt[i]-lt[i]-1)*heights[i];
        }
        
        return *max_element(rt.begin(),rt.end());
        
    }
};
   
