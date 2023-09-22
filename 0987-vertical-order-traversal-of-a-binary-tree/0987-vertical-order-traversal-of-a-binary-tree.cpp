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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes; // ITS OF THE FORM  NODE  , X COORDINAGTE AND Y COORDINATE 
        queue<pair<TreeNode*,pair<int,int>>>todo;// ITS OF THE FORM  NODE  , X COORDINAGTE AND Y COORDINATE 
        todo.push({root,{0,0}});
        while(!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;
            int x= p.second.first,y=p.second.second;
            
            nodes[x][y].insert(temp->val);
            if(temp->left)todo.push({temp->left,{x-1,y+1}});
            if(temp->right)todo.push({temp->right,{x+1,y+1}});
            
        }
        vector<vector<int>>ans;
        for(auto p : nodes)
        {
            vector<int>col;
            for(auto q:p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
                cout<<q.first<<endl ; 
                
            }
            ans.push_back(col);
        }
        
        return ans ;
    }
};