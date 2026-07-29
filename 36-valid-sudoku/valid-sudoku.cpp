class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0;i < 9; i++){
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> box;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row.find(board[i][j]) != row.end()){
                        return false;
                    }

                    row.insert(board[i][j]);
                }

                if(board[j][i] != '.'){
                    if(col.find(board[j][i]) != col.end()){
                        return false;
                    }

                    col.insert(board[j][i]);
                }

                // Check 3x3 box
                int r = 3 * (i / 3) + j / 3;
                int c = 3 * (i % 3) + j % 3;

                if(board[r][c] != '.'){
                    if(box.find(board[r][c]) != box.end()){
                        return false;
                    }

                    box.insert(board[r][c]);
                }
            }
        }

        return true;
    }
};