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
    TreeNode* createTree(int root, unordered_map<int, pair<int,int>> &mp){
        TreeNode* head = new TreeNode(root);
        if(mp.find(root) != mp.end()){
            if(mp[root].first != -1){
                head->left = createTree(mp[root].first, mp);
            }
            if(mp[root].second != -1){
                head->right = createTree(mp[root].second, mp);
            }
        }
        return head;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int, int>> mp;
        unordered_set<int> s;
        for(auto x: descriptions){
            int parent = x[0];
            int child = x[1];
            bool isLeft = x[2];

            if(mp.find(parent) == mp.end()){
                mp[parent] = {-1, -1};
            }
            s.insert(child);
            if(isLeft){
                mp[parent].first = child;
            }else{
                mp[parent].second = child;
            }

        }
        int root;
        for(auto x: mp){
            if(s.find(x.first) == s.end()){
                root = x.first;
                break;
            }
        }
        return createTree(root, mp);
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();