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
   // morris traversal 
//         vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>ans; 
//         TreeNode* curr = root ;
//         while(curr!=NULL)
//         {
//         if(curr->left==NULL) {ans.push_back(curr->val); 
//         curr= curr->right; }
//         else
//         {
//             TreeNode* prev = curr->left; 
//             while(prev->right!=NULL  && prev->right!=curr) prev= prev->right;
            
//             if(prev->right==NULL)
//             {
//                 prev->right = curr; 
//                 curr= curr->left; 
//             }
//             else
//             {
//                 prev->right = NULL ;
//                 ans.push_back(curr->val); 
//                 curr= curr->right; 
//             }
//         }
//         }
//         return ans  ;
//     }
    
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
    
// ALL TRVAERSAL IN ONE GO --------------------->>> EASY PEASY LEMON SQUEEEZY..................
//      vector<int> inorderTraversal(TreeNode* root)
//      {
//          stack<pair<TreeNode*, int>>st; 
//          st.push({root,1});
//              vector<int>pre,post,in; 
//          if(root ==NULL) return in; 
//          while(!st.empty())
//          {
//              auto it = st.top(); 
//              st.pop(); 
//             auto  curr = it.first ; 
//              int l = it.second ; 
//              if(l==1)
//              {
//                  pre.push_back(curr->val); 
//                  it.second++; 
//                  st.push(it); 
//                  if(curr->left!=NULL)
//                      st.push({curr->left,1}); 
//              }
             
//              else if(l==2)
//              {
//                  in.push_back(curr->val); 
//                  it.second++; 
//                  st.push(it); 
//                  if(curr->right)
//                      st.push({curr->right,1}); 
//              }
             
//              else 
//              {
//                  post.push_back(curr->val); 
//              }
//          }
         
//          return in ; 
//      }
        

};