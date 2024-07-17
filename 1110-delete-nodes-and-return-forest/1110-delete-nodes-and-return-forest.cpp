class Solution {
private:
    bool set[1001] = {};
    void dfs(TreeNode* &root, bool flag, vector<TreeNode*>& res){
        if (root == NULL) 
            return;
        dfs(root->left, set[root->val], res);
        dfs(root->right, set[root->val], res);
        if (!set[root->val] && flag) 
            res.push_back(root);
        if (set[root->val]) 
            root = NULL;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        for (int num : to_delete)
            set[num] = true;
        dfs(root, true, ans);
        return ans;
    }
};