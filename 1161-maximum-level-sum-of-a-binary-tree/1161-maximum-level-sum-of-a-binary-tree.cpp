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
    int maxLevelSum(TreeNode* root) {
        int large=INT_MIN;
        queue<TreeNode*>test;
        test.push(root);
        int i=0,level=0;
        while(!test.empty()){
            queue<TreeNode*>tempqueue;
            i++;
            int sum=0;
            while(!test.empty())
            {
                TreeNode* temp=test.front();
                sum+=temp->val;
                if(temp->left)
                    tempqueue.push(temp->left);
                if(temp->right)
                    tempqueue.push(temp->right);
                test.pop();             
            }
            if(sum>large){
                level=i;
                large=sum;
            }
            test=tempqueue;
        }
        return level;
    }
};