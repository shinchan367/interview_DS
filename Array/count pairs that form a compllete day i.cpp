class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum=hours[i]+hours[j];
                if(sum%24==0){
                    count+=1;
                }
            }
        }
        return count;
    }
};
