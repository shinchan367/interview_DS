//Example 1:
//Input: low = 100, high = 300
//Output: [123,234]

//Example 2:

//Input: low = 1000, high = 13000
//Output: [1234,2345,3456,4567,5678,6789,12345]
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        queue<int>q;
        for(int i=1;i<=9;i++){
            q.push(i);
        }
        vector<int>result;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            

            if(num>=low && num<=high){
                result.push_back(num);
            }
             if(num>high)break;
            if(num%10<9){
                int rem=num%10;
                q.push(num*10+rem+1);
            }
        }
        return result;
    }
};
 
