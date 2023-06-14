/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mar(TreeNode* root ,unordered_map<TreeNode* , TreeNode*>&mp   )
    {
        queue<TreeNode*>q ; 
        q.push(root) ; 
        while(q.size() )
        {
            TreeNode* temp = q.front() ;  q.pop() ; 
            if(temp->left ){
                mp[temp->left ] = temp ;
                 q.push(temp->left);
            } 
            if(temp->right) {mp[temp->right] = temp ;
                             q.push(temp->right);} 
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>mp ; 
        mar(root , mp) ; 
        unordered_map<TreeNode* , bool>visit ; 
        queue<TreeNode*>q  ;
         q.push( target) ;
        visit[target] = true ; 
        int cnt =0 ; 
        while(!q.empty())
        {int s = q.size() ; 
            if(cnt==k) break ;
            cnt++ ; 
            for(int i=0 ; i<s;i++)
            {
                TreeNode* temp = q.front() ;
                 q.pop() ; 
                
                if(temp->left && !visit[temp->left])
                {
                    q.push(temp->left) ; 
                    visit[temp->left] = true ; 
                }
                if(temp->right && !visit[temp->right])
                {
                    q.push(temp->right) ; 
                    visit[temp->right] = true ; 
                }
                if(mp[temp] && !visit[mp[temp]])
                {
                    q.push(mp[temp]) ; 
                    visit[mp[temp]] = true ; 
                }
            }
        }
        vector<int>ans ; 
        while(!q.empty())
        {
            TreeNode* t = q.front( ) ; 
            q.pop() ; 
            ans.push_back(t->val) ; 
        }
        return ans ; 
        
        
    }
};