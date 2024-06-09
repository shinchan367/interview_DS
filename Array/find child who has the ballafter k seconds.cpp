class Solution {
public:
    int numberOfChild(int n, int k) {
        int position = 0; // Initial position of the ball
        int direction = 1; // Initial direction: 1 for right, -1 for left

        for (int i = 0; i < k; ++i) {
            position += direction;
            if (position == 0 || position == n - 1) {
                direction *= -1; // Reverse the direction
            }
        }

        return position;
    }
};
    
