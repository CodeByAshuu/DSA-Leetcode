class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<pair<int, int>, int>> q;
        int sr = entrance[0];
        int sc = entrance[1];

        q.push({{sr,sc}, 0});
        maze[sr][sc] = '+';
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc<n && maze[nr][nc] == '.'){
                    if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                        return steps + 1;
                    }

                    maze[nr][nc] = '+';
                    q.push({{nr, nc}, steps + 1});
                } 
            }
        }

        return -1;
    }
};