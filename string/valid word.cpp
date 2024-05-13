class Solution {
public:
    bool isValid(string word) {
        unordered_set<char>s={'a','e','i','o','u','A','E','I','O','U'};
        int n=word.size();
        if(n<3) return false;
        bool df=false,lf=false,uf=false,vf=false,cf=false;

        for( auto c:word){
            if(!isdigit(c) && !isalpha(c)) return false;
            if(islower(c)) lf=true;
            if(isupper(c)) uf=true;
            if(isdigit(c))   df=true;
            if(s.count(c)) vf=true;
            else if(!s.count(c) && isalpha(c)) cf=true;
        }
        return ((df||uf||lf)&vf &cf);
    }
};
