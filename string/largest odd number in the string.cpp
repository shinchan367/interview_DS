 public:
    string maxOdd(string s) {
        // your code here
       
       for(int i=s.length()-1;i>=0;i--){
           if(s[i]%2!=0){
               string s1=s.substr(0,i+1);
               return s1;
           }
       }
       return "";
    }
};
