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
   
    int widthOfBinaryTree(TreeNode* root) {
   if(!root) return 0 ; 
        queue<pair<TreeNode*,long long int>>q; 
        q.push({root,0}); 
       long long  int ans =0 ; 
        while(!q.empty())
        {
          
         
            int idx = q.front().second ; 
            int s = q.size(); 
                 long long int first , last ; 
            for(int i= 0 ; i<s; i++)
            {
                long long int curr = q.front().second-idx ; 
                   TreeNode* node = q.front().first ; 
           cout<<curr<<endl ;
                q.pop(); 
                if(i==0)
                    first = curr ; 
                
                if(i==s-1)last = curr ; 
                if(node->left) q.push({node->left,(2*curr)}); 
                if(node->right) q.push({node->right,(2*curr)+1}); 
            }
            ans= max(ans , abs(last - first +1)); 
        }
        
        
        return ans ; 
        
    }
};