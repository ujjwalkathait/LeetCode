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
    long long ans = INT_MIN;
    const int mod = 1e9+7;
    int findSum(TreeNode* root){
        if(root == NULL) return 0;
        return root->val + findSum(root->left) + findSum(root->right);
    }
    int solve(TreeNode* root, long long totalSum){
        if(root == NULL) return 0;

        int subSum = root->val + solve(root->left, totalSum) + solve(root->right, totalSum);
        ans = max(ans, (totalSum - subSum)*subSum);
        return subSum;
    }
    int maxProduct(TreeNode* root) {
        long long totalSum = findSum(root);
        solve(root, totalSum);
        return ans % mod;
    }
};