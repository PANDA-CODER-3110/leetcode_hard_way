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
    bool insufficientTraversal(TreeNode* &root , int limit,int sum ){
        
        if(root == NULL)
            return false;
        
        if(root -> left == NULL && root -> right == NULL){
            
            if(sum+root->val >= limit)
                return true;
            
            return false;
            
        }
        
        bool left = insufficientTraversal(root->left , limit,sum+root->val);
        bool right= insufficientTraversal(root->right, limit,sum+root->val);
        
        if(left == false)
            root-> left = NULL;
        
        if(right == false)
            root->right = NULL ;
        
        if(left || right)
            return true;
        
        return false;
        
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        if(root == NULL)
            return NULL;
        
        bool ans = insufficientTraversal(root,limit,0);
        
        if(ans == false)
            return NULL;
        
        return root ;
    }
};