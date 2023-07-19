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
    void solve(TreeNode*root , int ans , int&res)
    {
         ans+=(root->val) ;
        if(root->left)solve(root->left  , ans*10 , res) ; 
        if(root->right)solve(root->right , ans*10 , res) ; 
        if(root->left==NULL && root->right ==NULL )
            res+=ans ; 
        ans/=10 ; 
        
    }
    int sumNumbers(TreeNode* root) {
        int res =0 ; 
        solve(root , 0 , res) ; 
        return res ; 
        
    }
};