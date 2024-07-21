class Solution {
public:
    bool doesAliceWin(string s) {
        int t=0;
        for(char c : s){
            if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') t++;
        }
        return (t>0);
    }
};
