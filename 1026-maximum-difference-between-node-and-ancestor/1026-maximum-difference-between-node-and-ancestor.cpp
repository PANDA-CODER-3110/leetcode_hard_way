class Solution {
public:
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root -> val, root -> val);
        return ans;
    }
    void dfs(TreeNode* root, int curMin, int curMax) {
        if(!root) return;
        ans = max({ans, root -> val - curMin, curMax - root -> val});
		curMin = min(curMin, root -> val);
        curMax = max(curMax, root -> val);
        dfs(root -> left, curMin, curMax);
        dfs(root -> right, curMin, curMax);
    }
};