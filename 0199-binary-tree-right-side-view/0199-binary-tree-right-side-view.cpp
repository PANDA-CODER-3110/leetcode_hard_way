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
    // void solve(TreeNode* root , int level , vector<int>&ans)
    // {
    //     if(root==NULL)  return ; 
    //     if(level == ans.size()) ans.push_back(root->val); 
    //     if(root->right) solve(root->right,level+1,ans); 
    //     if(root->left)  solve(root->left, level+1,ans); 
    // }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans ; 
        if(root == NULL) return ans ; 
        // int level = 0 ; 
        // solve(root , level , ans ); 
        // return ans ; 
        queue<TreeNode*>q ;
        q.push(root); 
        while(!q.empty())
        {
            int n = q.size(); 
            for(int i=0 ; i<n;i++)
            {
                auto it  = q.front(); 
                q.pop(); 
                if(i==n-1)
                {
                    ans.push_back(it->val); 
                }
                if(it->left)
                    q.push(it->left); 
                if(it->right)
                    q.push(it->right); 
            }
        }
        
        return ans ; 
        
    }
};