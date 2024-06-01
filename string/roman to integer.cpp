class Solution {
public:
    int Value(char ch){
        switch(ch){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;   
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
   
        }
        return 0;
    }

    int romanToInt(string s) {
        int n = s.size();
        int result = Value(s[n-1]);
        for(int i=n-2;i>=0;i--){
            if(Value(s[i]) < Value(s[i + 1])){
                result -= Value(s[i]);  // If current numeral is smaller than the next, subtract its value
            }
            else{
                result += Value(s[i]);  // Otherwise, add its value
            }
        }
        return result;
    }
};
