//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"


Output: true
class Solution {
public:
        int n,m,l;
        vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
        bool fun(int i,int j,vector<vector<char>>& board,string &word,int idx)
          {
                 if(idx>=l){
                     return true;
                 }
                 if(i<0||i>=n||j<0||j>=m||board[i][j]!=word[idx])
                 return false;
                 char temp=board[i][j];
                 board[i][j]='$';
                 for(auto & dir:directions){
                     int i_=i+dir[0];
                     int j_=j+dir[1];
                     if(fun(i_,j_,board,word,idx+1))
                     return true;
                 }
                 board[i][j]=temp;
                 return false;

           }
    bool exist(vector<vector<char>>& board, string word) {
         n=board.size();
         m=board[0].size();
         l=word.length();
        if(n*m<1){
            return false;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && fun(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
