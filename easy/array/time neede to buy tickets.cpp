//Input: tickets = [2,3,2], k = 2
//Output: 6
//Explanation: 
//- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
//- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
//The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.


class Solution {
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        int n=v.size();
        int t=0;
        while(true) {
            for(int i=0;i<n;i++) {
                if(v[i]>0) {
                    v[i]=v[i]-1;
                    t++;
                }
                if(i==k && v[i]==0)
                    return t;
            }
        }
        return 0;
    }
};
//***********************************************************************************************************//
class Solution {
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        int n=v.size();
        int value=v[k];
        int t=0;
        for(int i=0;i<n;i++) {
            if(i<k) {
                t=t+min(v[i],value);
            } else if(i==k) {
                t=t+value;
            } else {
                if(v[i]<value)
                    t=t+v[i];
                else
                    t=t+value-1;
            }
        }
        return t;
    }
};
