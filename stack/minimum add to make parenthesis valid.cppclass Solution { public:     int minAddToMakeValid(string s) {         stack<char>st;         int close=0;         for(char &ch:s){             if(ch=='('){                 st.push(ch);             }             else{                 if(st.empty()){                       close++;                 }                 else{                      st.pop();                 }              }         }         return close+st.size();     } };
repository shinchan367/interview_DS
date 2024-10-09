//o(n)
//o(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int close=0;
        for(char &ch:s){
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(st.empty()){
                      close++;
                }
                else{
                     st.pop();
                } 
            }
        }
        return close+st.size();
    }
};
//o(n)
//o(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                  open++;
            }
            else{
                if(open>0){
                open--;
                }
                else{
                    close++;
                }
            }
        }
        return open+close;
    }
};
