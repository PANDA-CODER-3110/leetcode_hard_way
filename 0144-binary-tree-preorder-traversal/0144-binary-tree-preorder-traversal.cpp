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
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int>ans ; 
        stack<TreeNode*>q ;
        if(!root) return ans  ; 
        q.push(root) ; 
        while(!q.empty())
        {
           root = q.top() ; 
            q.pop() ; 
            ans.push_back(root->val) ; 
            if(root->right!=NULL)
            {
                q.push(root->right); 
            }
           if(root->left!=NULL)
           {
               q.push(root->left); 
           }
           
            
        }
        return ans ; 
        
    }
};