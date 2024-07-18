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
    vector<int> solve(TreeNode* root, int distance, int &count){
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {1};

        vector<int> left = solve(root->left, distance, count);
        vector<int> right = solve(root->right, distance, count);

        for(auto i: left){
            for(auto j: right){
                if(i + j <= distance){
                    count++;
                }
            }
        }

        vector<int> parent;
        for(auto i: left){
            if(i+1 <= distance){
                parent.push_back(i+1);
            }
        }
        for(auto i: right){
            if(i+1 <= distance){
                parent.push_back(i+1);
            }
        }

        return parent;
    }
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        solve(root, distance, count);
        return count;
    }
};