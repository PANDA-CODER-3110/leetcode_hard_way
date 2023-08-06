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
   TreeNode* build(vector<int>& preorder, vector<int>& inorder, int&ind , int left , int right){
        if(left>right )return NULL ; 
        int pivot = left ; 
        while(inorder[pivot]!=preorder[ind])pivot++ ; 
        ind++ ; 
        TreeNode* node = new TreeNode(inorder[pivot]) ; 
       node->right = build(preorder , inorder , ind , pivot+1 , right) ; 
        node->left = build(preorder , inorder , ind , left , pivot-1) ; 
        
        return node ; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& po) {
       reverse(po.begin(),po.end()) ; 
           int ind =0 ; 
        return build(po, inorder , ind , 0 , inorder.size()-1) ; 
        
    }
};