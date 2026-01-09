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
    unordered_map<TreeNode*, int> dp;
    int dfs(TreeNode* root) {
        if(!root) return 0;

        if(dp.count(root)) return dp[root];

        int take = root->val;
        int notTake = dfs(root->left) + dfs(root->right);

        if(root->left) take += dfs(root->left->left) + dfs(root->left->right);
        if(root->right) take += dfs(root->right->left) + dfs(root->right->right);

        return dp[root] = max(take, notTake);
        
    }
    int rob(TreeNode* root) {

        return dfs(root);
    }
};