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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind =0 ; 
        return build(preorder, inorder , ind , 0 , preorder.size()-1) ; 
        
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int&ind , int left , int right){
        if(left>right )return NULL ; 
        int pivot = left ; 
        while(inorder[pivot]!=preorder[ind])pivot++ ; 
        ind++ ; 
        TreeNode* node = new TreeNode(inorder[pivot]) ; 
        node->left = build(preorder , inorder , ind , left , pivot-1) ; 
        node->right = build(preorder , inorder , ind , pivot+1 , right) ; 
        return node ; 
    }
        
    
};