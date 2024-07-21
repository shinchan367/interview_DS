class Solution {
public:
    int minChanges(int n, int k) {
        int changes = 0;
        
        for (int i = 0; i < 31; ++i) {
            int bitN = n & (1 << i);
            int bitK = k & (1 << i);
            
            if (bitK == 0 && bitN != 0) {
                n ^= (1 << i);
                changes++;
            }
        }
        
        return (n == k) ? changes : -1;
    }
};
//**************************************************************************************
class Solution {
public:
    int minChanges(int n, int k) {
        int changes = 0;
        
        for (int i = 0; i < 31; ++i) {
            int bitN = n & (1 << i);
            int bitK = k & (1 << i);
            
            if (bitK == 0 && bitN != 0) {
                n ^= (1 << i);
                changes++;
            }
        }
        
        return (n == k) ? changes : -1;
    }
};
//***********************************************************************************************
class Solution {
public:
    int minChanges(int n, int k) {
        if ((n & k) != k) {
        return -1;
    }

    int count1_n = std::bitset<32>(n).count();
    int count1_k = std::bitset<32>(k).count();

    return count1_n - count1_k;
    }
};
