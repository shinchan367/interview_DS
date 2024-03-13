//For x to be a pivot integer, the sum of elements from 1 to x should be equal to the sum from x to n.

//[1 + 2 + 3 + 4 + 5 + 6 = 21] and [6 + 7 + 8 = 21].

//The pivot integer x for this example is 6, as the sum of elements from 1 to 6 is equal to the sum of elements from 6 to 8.

//Approach 1: Brute Force
class Solution {
public:
    int pivotInteger(int n) {
        // Iterate through possible pivot values
        for (int i = 1; i <= n; i++) {
            int sumLeft = 0;
            int sumRight = 0;

            // Calculate the sum of elements on the left side of the pivot
            for (int j = 1; j <= i; j++) {
                sumLeft += j;
            }

            // Calculate the sum of elements on the right side of the pivot
            for (int k = i; k <= n; k++) {
                sumRight += k;
            }

            // Check if the sums on both sides are equal
            if (sumLeft == sumRight) {
                return i; // Return the pivot value if found
            }
        }

        return -1; // Return -1 if no pivot is found
    }
};
//Approach 2: Two Pointer
class Solution {
public:
    int pivotInteger(int n) {
        int leftValue = 1;
        int rightValue = n;
        int sumLeft = leftValue;
        int sumRight = rightValue;

        if (n == 1) return n;
        
        // Iterate until the pointers meet
        while (leftValue < rightValue) {
            // Adjust sums and pointers based on comparison
            if (sumLeft < sumRight) {
                sumLeft += ++leftValue;
            } else {
                sumRight += --rightValue;
            }

            // Check for pivot condition
            if (sumLeft == sumRight && leftValue + 1 == rightValue - 1) {
                return leftValue + 1;
            }
        }

        return -1; // Return -1 if no pivot is found
    }
};

//Approach 3: using math

class Solution {
 public:
  int pivotInteger(int n) {
        const int sum = (n * (n + 1) / 2);
        const int pivot = sqrt(sum);
        // If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot * pivot == sum ? pivot : -1;
  }
};
