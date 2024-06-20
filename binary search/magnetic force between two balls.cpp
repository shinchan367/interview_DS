class Solution {
public:
    int sol(vector<int>&arr,int mid,int n)
    {
        int curr=arr[0];
        int ans=1;

        for(int i=1;i<n;i++)
        {
            if(arr[i]-curr>=mid)
            {
                ans++;
                curr=arr[i];
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();

        int low=0,high=position[n-1],mid;

        while(low<=high)
        {
            mid=(low+high)/2;

            if(sol(position,mid,n)>=m) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
//**********************************************************************************************************************************************************************************
class Solution {
public:

    bool possibleToPlace(int force, vector<int>& position, int m) {

        int prev       = position[0];
        int countBalls = 1;


        for(int i = 1; i < position.size(); i++) {
            int curr = position[i];

            if(curr - prev >= force) {
                countBalls++;
                prev = curr;
            }

            if(countBalls == m)
                break;
        }

        return countBalls == m;

    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(begin(position), end(position));

        int minForce = 1;
        int maxForce = position[n-1] - position[0]; //better value (comment me batao)

        int result = 0;
        while(minForce <= maxForce) {
            int midForce = minForce + (maxForce - minForce)/2;

            if(possibleToPlace(midForce, position, m)) {
                result = midForce;
                minForce = midForce+1;
            } else {
                maxForce = midForce-1;
            }
        }

        return result;
    }
};
