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
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == NULL){
            return ;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* inorderToBST(int s, int e, vector<int> &arr){
        if(s > e){
            return NULL;
        }
        int mid = s + (e-s)/2;
        TreeNode* newRoot = new TreeNode(arr[mid]);

        newRoot->left = inorderToBST(s, mid-1, arr);
        newRoot->right = inorderToBST(mid+1, e, arr);

        return newRoot;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        
        return inorderToBST(0, arr.size()-1, arr);
    }
};