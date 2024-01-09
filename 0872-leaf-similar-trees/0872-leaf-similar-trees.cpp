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
    vector<int>a1,a2; 
    void solve(TreeNode* a,vector<int>&l)
    {
        if(!a) return ; 
        if(!a->left && !a->right) l.push_back(a->val); 
        
        if(a->left)solve(a->left,l); 
        if(a->right)solve(a->right,l); 
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1,a1); 
        solve(root2,a2);
        return a1==a2;
    }
};