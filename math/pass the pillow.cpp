/************************************************************ C++ ************************************************************/
//Approach-1 (Simple Simulation)
//T.C : O(time)
//S.C : O(1)
class Solution {
public:
    int passThePillow(int n, int time) {
        int idx  = 1;
        int dir  = 1;

        while(time > 0) {
            if(idx + dir >=1 && idx + dir <= n) {
                idx += dir;
                time--;
            } else {
                dir *= -1;
            }
        }
        return idx;
    }
};



//Approach-2 (Simple Maths)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int passThePillow(int n, int time) {
        
        int totalFullRounds = time / (n-1);

        int timeLeft        = time % (n-1);

        if(totalFullRounds % 2 == 0) {
            return timeLeft + 1;
        } else {
            return n - timeLeft;
        }

        return -1;
    }
};
