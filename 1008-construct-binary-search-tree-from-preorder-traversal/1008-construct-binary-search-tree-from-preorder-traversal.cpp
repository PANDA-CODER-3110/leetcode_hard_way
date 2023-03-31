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
    int i=0 ; 
    TreeNode* bstFromPreorder(vector<int>& preorder,int mm = INT_MAX) {
        if(i==preorder.size() || preorder[i]>mm) return NULL ; 
        TreeNode* curr = new TreeNode(preorder[i++]); 
        curr->left = bstFromPreorder(preorder,curr->val); 
        curr->right = bstFromPreorder(preorder,mm); 
        
        return curr  ; 
    }
};