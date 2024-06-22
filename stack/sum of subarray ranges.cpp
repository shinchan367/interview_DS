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
