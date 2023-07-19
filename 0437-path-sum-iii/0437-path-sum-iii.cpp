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
       int count = 0;
    int pathSum(TreeNode *root, int k)
    {
        if (root == NULL)
        {
            return 0;
        }
        solve(root, k);
        pathSum(root->left, k);
        pathSum(root->right, k);
        return count;
    }
    void solve(TreeNode *root, long long int k)
    {
        if (root == NULL)
        {
            return;
        }
        if (k == root->val)
        {
            count++;
        }
        solve(root->right, k - root->val);
        solve(root->left, k - root->val);
    }
};