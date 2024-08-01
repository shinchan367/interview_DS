class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++){
              if(((details[i][11]-'0')*10+(details[i][12]-'0'))>60){
                count++;
                continue;
              }
        }
        return count;
    }
};
//**********************************************************************************************
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& x : details) {
            int age = stoi(x.substr(11, 2));
            ans += age > 60;
        }
        return ans;
    }
};
