//Input: root = [2,1,1,1,3,null,null,null,null,null,1]
//Output: 1 
//Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).




//Approach-1 (Simple and straight forward)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, vector<int>& temp) {
        if(root != NULL) {
            temp[root->val]++;
            
            if(root->left == NULL && root->right == NULL) {
                int oddFreq = 0;
                for(int i = 1; i <= 9; i++) {
                    if(temp[i]%2 != 0) {
                        oddFreq++;
                    }
                }

                result += oddFreq <= 1;
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);
            
            temp[root->val]--;

        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> temp(10, 0);
        
        solve(root, temp);
        return result;
    }
};

//Approach-2 (Using bit magic)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, int temp) {
        if(root != NULL) {
            
            temp = temp ^ (1 << root->val);
            
            if(root->left == NULL && root->right == NULL) {
                if((temp & (temp - 1)) == 0) { //Make sure to put (temp & (temp - 1)) entirely in bracket because precedence of == is high
                    result++;
                }
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);


        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {

        solve(root, 0);
        return result;
    }
};
