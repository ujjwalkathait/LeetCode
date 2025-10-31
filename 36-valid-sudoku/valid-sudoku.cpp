class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_set<int>> row(n), col(n), box(n);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                if(row[i].find(board[i][j]) != row[i].end()) return false;
                row[i].insert(board[i][j]);
                if(col[j].find(board[i][j]) != col[j].end()) return false;
                col[j].insert(board[i][j]);
                int idx = (i/3) * 3 + (j/3);
                if(box[idx].find(board[i][j]) != box[idx].end()) return false;
                box[idx].insert(board[i][j]);
            }
        }
        return true;
    }
};