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
    int sum =0 ; 
    int solve(TreeNode* root, int l, int r)
              {
                  if(root)
                  {
                      solve(root->left,l,r); 
                      if(root->val<=r && root->val>=l)
                          sum+=root->val ; 
                      solve(root->right, l , r); 
                      
                  }
                  return sum ; 
              }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0 ; 
        return solve(root , low ,high);
        
    }
};