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
    vector<int>m; 
    vector<int> postorderTraversal(TreeNode* root) {
//       vector<int>ans; 
//         if(root==NULL) return ans ; 
//         stack<TreeNode*>st ; 
//         st.push(root); 
//         while(!st.empty())
//         {
//             root = st.top(); 
//             st.pop();
//                  if(root->left!=NULL)
//            {
//                st.push(root->left); 
//            }
         
//              if(root->right!=NULL)
//             {
//                 st.push(root->right); 
//             }
          
        
           
//                ans.push_back(root->val); 
            
//         }
//         reverse(ans.begin(),ans.end()); 
//         return ans ; 
               vector<int>ans; 
        TreeNode* curr = root ;
        while(curr!=NULL)
        {
        if(curr->right==NULL) {ans.push_back(curr->val); 
        curr= curr->left; }
        else
        {
            TreeNode* prev = curr->right; 
            while(prev->left!=NULL  && prev->left!=curr) prev= prev->left;
            
            if(prev->left==NULL)
            {
                prev->left = curr; 
                 ans.push_back(curr->val); 
                curr= curr->right; 
            }
            else
            {
                prev->left = NULL ;
               
                curr= curr->left; 
            }
        }
        }
        
        reverse(ans.begin(),ans.end()); 
        return ans  ;
        
    }
};