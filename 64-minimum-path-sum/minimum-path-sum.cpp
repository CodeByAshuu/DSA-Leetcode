class Solution {
public:
    int minPathSum(int i, int j, int m, int n, vector<vector<int>>& grid) {
        vector<int> curr(n, 0);
        vector<int> prev(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[0] = grid[0][0];
                }else{
                    int up = 1e9;
                    if(i > 0){
                        up = grid[i][j]+prev[j];
                    }

                    int left = 1e9;
                    if(j > 0){
                        left = grid[i][j] + curr[j-1];
                    }

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        int i = m - 1;
        int j = n - 1;
        return minPathSum(i, j, m, n, grid);
    }
};