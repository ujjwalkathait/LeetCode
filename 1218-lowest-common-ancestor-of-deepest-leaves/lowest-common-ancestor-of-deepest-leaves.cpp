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
    TreeNode* lca(TreeNode* root, int n1, int n2) {
        if (!root) return NULL;
        if (root->val == n1 || root->val == n2) return root;

        TreeNode* leftLca = lca(root->left, n1, n2);
        TreeNode* rightLca = lca(root->right, n1, n2);
        if (leftLca && rightLca)
            return root;

        return leftLca ? leftLca : rightLca;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        map<int, vector<TreeNode*>> mp;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                mp[level].push_back(front);

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            level++;
        }
        vector<TreeNode*> deepNodes = mp.rbegin()->second;
        if(deepNodes.size() < 2) return deepNodes[0];
        TreeNode *ans = deepNodes[0];
        for(int i=1; i<deepNodes.size(); i++){
            ans = lca(root, ans->val, deepNodes[i]->val);
        }
        return ans;
    }
};