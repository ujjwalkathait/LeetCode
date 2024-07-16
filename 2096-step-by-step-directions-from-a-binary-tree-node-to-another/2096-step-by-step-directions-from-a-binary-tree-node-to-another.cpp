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
    bool LCA(TreeNode* root, int value, vector<string> &ans){
        if(root == NULL){
            return false;
        }
        if(root->val == value){
            return true;
        }
        ans.push_back("R");
        if(LCA(root->right, value, ans)){
            return true;
        }
        ans.pop_back();

        ans.push_back("L");
        if(LCA(root->left, value, ans)){
            return true;
        }
        ans.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<string> s1, s2;
        LCA(root, startValue, s1);
        LCA(root, destValue, s2);

        int len = 0;
        while (len < s1.size() && len < s2.size() && s1[len] == s2[len]) {
            len++;
        }
        vector<string> res(s1.size() - len, "U");
        res.insert(res.end(), s2.begin() + len, s2.end());

        string result;
        for (const auto& dir : res) {
            result += dir;
        }
        return result;

    }
};