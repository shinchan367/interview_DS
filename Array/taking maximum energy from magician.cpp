class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();          //Better    ||   T.C --> O(k x n)       ||   S.C --> O(1)  
        
        int ans = INT_MIN;
        
        for(int i=0; i<k; i++) {
            
            int sum = energy[i];
            
            for(int j = (i+k); j < n; j += k) {
                
                if((sum + energy[j]) > energy[j])
                    sum += energy[j];
                
                else
                    sum = energy[j];
            }
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
