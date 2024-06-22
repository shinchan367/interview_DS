class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int unsat=0;
        for(int i=0;i<minutes;i++){
             unsat+=customers[i]*grumpy[i];
        }
        int maxuns=unsat;
        int i=0,j=minutes;
        while(j<n){
            unsat+=customers[j]*grumpy[j];
            unsat-=customers[i]*grumpy[i];
            maxuns=max(maxuns,unsat);
            i++;
            j++;
        }
        int total=maxuns;

        for(int i=0;i<n;i++){
            total+=customers[i]*(1-grumpy[i]);
        }
        return total;
    }
};
