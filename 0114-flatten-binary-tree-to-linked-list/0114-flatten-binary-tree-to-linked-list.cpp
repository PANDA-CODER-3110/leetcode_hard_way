/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 Approach: (As mentioned by Striver)

At a node(say cur) if there exists a left child, we will find the rightmost node in the left subtree(say prev).
We will set prev’s right child to cur’s right child,
We will then set cur’s right child to it’s left child.
We will then move cur to the next node by assigning cur it to its right child
We will stop the execution when cur points to NULL.
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return  ; 
        TreeNode* curr= root ; 
        while(curr)
        {
            if(curr->left){
                TreeNode*pre = curr->left ; 
                while(pre->right)
                {
                    pre = pre->right ; 
                }
                pre->right = curr->right ; 
                curr->right = curr->left ; 
                curr->left = NULL ; 
            }
            curr= curr->right ; 
        }
    }
};