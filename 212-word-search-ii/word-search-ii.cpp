class Solution {
public:
    struct Node{
        string word;
        bool endOfWord;
        Node *children[26];
    };
    Node* newNode(){
        Node *root = new Node();
        root->word = "";
        root->endOfWord = false;
        for(int i=0; i<26; i++){
            root->children[i] = NULL;
        }
        return root;
    }
    void insert(string word, Node *root){
        Node *temp = root;
        for(int i=0; i<word.size(); i++){
            if(temp->children[word[i]-'a'] == NULL){
                temp->children[word[i]-'a'] = newNode();
            }
            temp = temp->children[word[i]-'a'];
        }
        temp->endOfWord = 1;
        temp->word = word;
    }
    void dfs(vector<vector<char>> &board, int i, int j, Node* root, vector<string> &ans){
        if(i < 0 || j < 0 || i>=board.size() || j>=board[0].size() || board[i][j] == '.' || root->children[board[i][j] - 'a'] == NULL){
            return;
        }
        root = root->children[board[i][j] - 'a'];
        if(root->endOfWord == 1){
            ans.push_back(root->word);
            root->endOfWord = 0;
        }
        char ch = board[i][j];
        board[i][j] = '.';

        dfs(board, i-1, j, root, ans);
        dfs(board, i, j-1, root, ans);
        dfs(board, i+1, j, root, ans);
        dfs(board, i, j+1, root, ans);
        

        board[i][j] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        
        vector<string> ans;
        Node *root = newNode();
        for(auto word: words) insert(word, root);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(root->children[board[i][j]-'a'] != NULL){
                    dfs(board, i, j, root, ans);
                }
            }
        }
        return ans;
    }
};