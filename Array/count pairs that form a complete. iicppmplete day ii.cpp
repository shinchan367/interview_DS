class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
       int n = hours.size();
        vector<int> remainderCount(24, 0);
        long long count = 0;
        
    
        for(int i = 0; i < n; ++i) {
            remainderCount[hours[i] % 24]++;
        }
        
    
        for(int i = 1; i < 12; ++i) {
            count += (long long)remainderCount[i] * remainderCount[24 - i];
        }
        
    
        count += (long long)remainderCount[0] * (remainderCount[0] - 1) / 2;
        count += (long long)remainderCount[12] * (remainderCount[12] - 1) / 2;
        
        return count;
        }    
};
