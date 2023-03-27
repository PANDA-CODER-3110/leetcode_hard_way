/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root , int &ma )
    {
        if(root ==NULL) return 0;
        int l = max(0,solve(root->left,ma));
        int r = max(0,solve(root->right,ma));
        ma = max(ma,l+r+root->val);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
       
       int ma=INT_MIN;
        solve(root, ma );
        return ma;
    }
};