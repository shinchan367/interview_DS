//Input: root = [1,2,3]
//Output: 25
//Explanation:
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//Therefore, sum = 12 + 13 = 25.

//Recursion-1
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    
    int find(TreeNode* root, int curr) {
        
        if(!root)
            return 0;
        
        curr = curr*10 + root->val;
        
        if(root->left == NULL && root->right == NULL) {
            return curr;
        }
        
        int left_num  = find(root->left, curr);
        int right_num = find(root->right, curr);
        
        return left_num + right_num;
    }
    
    int sumNumbers(TreeNode* root) {
        return find(root, 0);
    }
};
