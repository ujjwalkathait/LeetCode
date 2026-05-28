// class Solution {
//     vector<string> words;
//     class TrieNode {
//         public:
//         TrieNode* children[26];
//         int idx;
//         TrieNode(int idx) {
//             this->idx = idx;
//             for (int i = 0; i < 26; i++) {
//                 children[i] = NULL;
//             }
//         }
//     };
//     void insert(string &word, TrieNode *root, int index){
//         for(int i=word.size()-1; i>=0; i--){
//             int id = word[i] - 'a';
//             if(root->children[id] == NULL){
//                 root->children[id] = new TrieNode(index);
//             }
//             root = root->children[id];
//             if(words[root->idx].size() > word.size()){
//                 root->idx = index;
//             }
//         }
//     }
//     int search(string &word, TrieNode *root){
//         TrieNode *node = root;
//         int ans = root->idx;
//         for(int i=word.size()-1; i>=0; i--){
//             int id = word[i] - 'a';
//             node = node->children[id];
//             if(node == NULL) return ans;
//             ans = node->idx;
//         }

//         return ans;
//     }
// public:
//     vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
//         TrieNode *root = new TrieNode(0);


//         words = wordsContainer;
//         for(int i=0; i<wordsContainer.size(); i++){
//             if(wordsContainer[root->idx].size() > wordsContainer[i].size()){
//                 root->idx = i;
//             }
//             insert(wordsContainer[i], root, i);
//         }
//         vector<int> ans;
//         for(int i=0; i<wordsQuery.size(); i++){
//             ans.push_back(search(wordsQuery[i], root));
//         }
//         return ans;
//     }
// };

class Solution {
    struct TrieNode {
        int children[26];
        int bestLen;
        int bestIdx;
        
        TrieNode() {
            fill(begin(children), end(children), -1);
            bestLen = 1e9;
            bestIdx = 1e9;
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<TrieNode> trie;
        trie.emplace_back();
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            int len = wordsContainer[i].length();
            int curr = 0;
            
            if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
                trie[curr].bestLen = len;
                trie[curr].bestIdx = i;
            }
            
            for (int j = len - 1; j >= 0; j--) {
                int charIdx = wordsContainer[i][j] - 'a';
                
                if (trie[curr].children[charIdx] == -1) {
                    trie[curr].children[charIdx] = trie.size();
                    trie.emplace_back();
                }
                
                curr = trie[curr].children[charIdx];
                
                if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
                    trie[curr].bestLen = len;
                    trie[curr].bestIdx = i;
                }
            }
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& query : wordsQuery) {
            int curr = 0;
            int len = query.length();
            
            for (int j = len - 1; j >= 0; j--) {
                int charIdx = query[j] - 'a';
                if (trie[curr].children[charIdx] == -1) {
                    break;
                }
                curr = trie[curr].children[charIdx];
            }
            ans.push_back(trie[curr].bestIdx);
        }
        
        return ans;
    }
}; 