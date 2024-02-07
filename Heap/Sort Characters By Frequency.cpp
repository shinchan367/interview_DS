//Approach-2 (Using Priority Queue) - O(nlong)
//Input: s = "tree"
//Output: "eert"
//Explanation: 'e' appears twice while 'r' and 't' both appear once.
//So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

class Solution {
public:
         typedef pair<char, int> P;
    struct comp {
        bool operator()(P &p1, P &p2) {
            return p1.second<p2.second; //max-heap
        }
    };

    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;
        unordered_map<char,int>mp;
        for(auto &it:s){
            mp[it]++;
        }
        for(auto &i:mp){
            pq.push({i.first,i.second});
        }
        string result="";
        while(!pq.empty()){
            P temp=pq.top();
            pq.pop();
            result+=string(temp.second,temp.first);
        }
        return result;
    }
};
