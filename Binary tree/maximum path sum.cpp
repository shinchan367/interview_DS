class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        sum(root,maxi);
        return maxi;
    }
    int sum(TreeNode* root ,int& maxi){
        if(!root)return 0;
        int lh=max(0,sum(root->left,maxi));
        int rh=max(0,sum(root->right,maxi));
        int val=root->val;
        maxi=max(maxi,(lh+rh)+val);
        return max(lh,rh)+val;
    }
};
