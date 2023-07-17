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
void minimum(TreeNode* root,int&mini,int&preVal)
    {
        if(root==NULL)
            return;
        minimum(root->left,mini,preVal);              // to left travel   
        if(preVal!=-1){                               // if there is any previous value then compare to minimum
            mini=min(mini,abs(preVal-root->val));
        }
        preVal=root->val;                             // alloting the value of root in prevVal
        minimum(root->right,mini,preVal);             // then checking also for MINIDIFF in right
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=1e9;
        int preval=-1;
        minimum(root,mini,preval);
        return mini;
    }
};