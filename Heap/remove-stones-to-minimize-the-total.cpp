class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(!pq.empty() && k>0){
            int maxi_top=pq.top();
            pq.pop();
            int reduced=maxi_top-(maxi_top/2);
            pq.push(reduced);
            k--;
        }
        int sum=0;
         while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
/////
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        std::priority_queue<int, std::vector<int>, std::less<int>> que(piles.begin(), piles.end());
        for (auto num : piles) {
            sum += num;
        }
        while(k-- > 0) {
            auto top = que.top();
            int half = top / 2;
            sum -= half;
            que.pop();
            que.push((top - half));
        }
        return sum;
    }
};
