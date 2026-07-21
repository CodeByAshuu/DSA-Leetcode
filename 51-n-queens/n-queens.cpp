class Solution {
public:
    bool isSafe(int row, int column, vector<string>& board, int n){
        for(int j = 0; j < column; j++) {
            if(board[row][j] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = column - 1;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q') {
                return false;
            }

            i--;
            j--;
        }

        // Check lower-left diagonal
        i = row + 1;
        j = column - 1;

        while(i < n && j >= 0) {
            if(board[i][j] == 'Q') {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
    void NQueen(vector<vector<string>>& result, int column,vector<string>& board,int n){
        if(column == n){
            result.push_back(board);
        }

        // edge case

        // main logic
        for(int row = 0; row < n; row++){
            if(isSafe(row, column, board, n)){
                board[row][column] = 'Q';
                NQueen(result, column+1, board, n);
                board[row][column] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string s(n,'.');
        vector<string> board(n,s);
        int column = 0;
        NQueen(result, column, board, n);
        return result;
    }
};