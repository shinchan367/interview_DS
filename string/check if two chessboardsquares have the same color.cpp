class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int a=coordinate1[0]-'a';
        int b=coordinate2[0]-'a';
        if((a+coordinate1[1])%2==0 && (b+coordinate2[1])%2==0) {
            return true;
        }
        else if((a+coordinate1[1])%2!=0 && (b+coordinate2[1])%2!=0){
            return true;
        }
        return false;
    }
};
