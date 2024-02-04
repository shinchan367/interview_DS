/*int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

      /*  while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

         //   while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
            //    if(map[s[begin++]]++ ?){ /*modify counter here*/ }
           // }  

            /* update d here if finding maximum*/
      //  }
      //  return d;
 // }*/
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.





class Solution {

public:
    string minWindow(string s, string t) {
        int n = s.length();
        map<char, int> mp;
        
        for(char &ch : t) {
            mp[ch]++;
        }
        
        int requiredCount = t.length();
        int i = 0, j  = 0;
        int minStart  = 0;
        int minWindow = INT_MAX;
        while(j < n) {
            char ch_j = s[j];
            if(mp[ch_j] > 0)
                requiredCount--;
            
            mp[ch_j]--;
            
            while(requiredCount == 0) { //try to shrink the window
                if(minWindow > j-i+1) {
                    minWindow = j-i+1;
                    minStart  = i;
                }
                
                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i] > 0)
                    requiredCount++;
                i++;
            }
            
            j++; //Don't ever forget this :-)
        }
        
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};
  
