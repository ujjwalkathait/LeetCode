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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int, priority_queue<int, vector<int>, greater<int>>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int>> ans;
        
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int no = temp.second.first;
            int lvl = temp.second.second;
            TreeNode* frontNode = temp.first;

            mp[no][lvl].push(frontNode->val);
            if(frontNode->left){
                q.push({frontNode->left, {no-1, lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right, {no+1, lvl+1}});
            }
        }
        for(auto x: mp){
            vector<int> temp;
            auto val = x.second;
            for(auto y: val){
                auto pq = y.second;
                while(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};