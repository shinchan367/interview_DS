//O(N)
//O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            freq[ s[i]- 'a']++;
        }
        for(int i=0;i<t.size();i++){
            freq[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};
//*************************************************************************************************************************************
//O(Nlogn)
//O(1)
bool CheckAnagrams(string str1, string str2)
{
  // Case 1: when both of the strings have different lengths
  if (str1.length() != str2.length())
    return false;
 
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
  for (int i = 0; i < str1.length(); i++)
  {
    if (str1[i] != str2[i])
      return false;
  }
  return true;
}
//**************************************************************************************************************************************
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        if(n!=m){
            return false;
        }
        int count[128]={0};
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        for(int i=0;i<m;i++){
            count[t[i]]--;
        }
        for(int i=0;i<128;i++){
            if(count[i]!=0)
            return false;
        }
        return true;
    }
};
