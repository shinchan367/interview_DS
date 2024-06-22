class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> NSL = getNSL(nums);
        vector<int> NSR = getNSR(nums);
        vector<int> NGL = getNGL(nums);
        vector<int> NGR = getNGR(nums);

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            long long lg = i - NGL[i];
            long long rg = NGR[i] - i;
            sum += ((lg * rg) - (ls * rs)) * nums[i];
        }
        return sum;
    }

    vector<int> getNSL(const vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            v[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> getNSR(const vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) s.pop();
            v[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> getNGL(const vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] <= nums[i]) s.pop();
            v[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> getNGR(const vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] < nums[i]) s.pop();
            v[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return v;
    }
};
//*********************************************************************************************************************************
class Solution {
  public:
  // finding NSL
    vector<int> getNSL(vector<int>& nums , int n){
        vector<int> v(n);
        stack<int> s;
        for(int i = 0 ;i<n;i++){
            if(s.empty()){
            v[i]=-1;
            }else{
                 while(s.size()!=0 && nums[s.top()]>nums[i]){
                     s.pop();
                 }
                 if(s.size()==0){
                     v[i]=-1;
                 }else{
                     v[i]=s.top();
                 }
             }
             s.push(i);

        }
        return v;
    }
    //finding NSR
     vector<int> getNSR(vector<int>& nums , int n){
        vector<int> v(n);
                stack<int> s;

        for(int i = n-1 ;i>=0;i--){
            if(s.empty()){
            v[i]=n;
            }else{
                 while(s.size()!=0 && nums[s.top()]>=nums[i]){
                     //we handle duplicates by = sign in one case
                     s.pop();
                 }
                 if(s.size()==0){
                     v[i]=n;
                 }else{
                     v[i]=s.top();
                 }
             }
             s.push(i);

        }
        return v;
    }
    // finding NGR
    vector<int> getNGR(vector<int>& nums , int n){
        vector<int> v(n);
                stack<int> s;

        for(int i = n-1 ;i>=0;i--){
            if(s.empty()){
            v[i]=n;
            }else{
                 while(s.size()!=0 && nums[s.top()]<=nums[i]){
                     //we handle duplicates by = sign in one case
                     s.pop();
                 }
                 if(s.size()==0){
                     v[i]=n;
                 }else{
                     v[i]=s.top();
                 }
             }
             s.push(i);

        }
        return v;
    }
    //finding NGL
    vector<int> getNGL(vector<int>& nums , int n){
        vector<int> v(n);
                stack<int> s;

        for(int i = 0 ;i<n;i++){
            if(s.empty()){
            v[i]=-1;
            }else{
                 while(s.size()!=0 && nums[s.top()]<nums[i]){
                     s.pop();
                 }
                 if(s.size()==0){
                     v[i]=-1;
                 }else{
                     v[i]=s.top();
                 }
             }
             s.push(i);

        }
        return v;
    }

   // approach for this is the same as the sum of minimums in a subarray
   // first we find  the sum of maximums in a subarray 
   //second we find the sum of minimums in a subarray 
   //later we subtract them and we get the sum of the ranges 
   // sum of maximums of two arrays be a + b
   // sum of minimums of two arrays be c + d
   //we subtract (a+b)-(c+d);
   // we can write as (a-c)+(b-d)
    long long subarrayRanges(int n, vector<int> &nums) {
        // code here
         vector<int> NGL = getNGL(nums,n);
        vector<int> NGR = getNGR(nums,n);
        vector<int> NSL = getNSL(nums,n);
        vector<int> NSR = getNSR(nums,n);
        long long sum = 0;
        for(int i =0;i<n;i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i]-i;
            long long lg = i - NGL[i];
            long long rg = NGR[i]-i;
            long long totalsum = ((lg*rg)-(ls*rs))*nums[i];
            sum = sum+totalsum;
        }
        return sum ;
    }
};
