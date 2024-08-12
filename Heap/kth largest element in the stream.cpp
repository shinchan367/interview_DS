//Approach - (Using min-heap)
//T.C : O(n*logK)
//S.C : O(K)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
         if(pq.size() > K)
            pq.pop();
        
        return pq.top();
    }
};
//******************************************************brute force approach*******************************************************
#include <vector>
#include <algorithm>
using namespace std;

class KthLargest {
public:
    int K;
    vector<int> elements;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        elements = nums;
        sort(elements.begin(), elements.end(), greater<int>()); // Sort in descending order
    }

    int add(int val) {
        elements.push_back(val); // Add the new element
        sort(elements.begin(), elements.end(), greater<int>()); // Sort again

        // Return the Kth largest element
        return elements[K - 1];
    }
};
