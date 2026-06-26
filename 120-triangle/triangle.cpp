class Solution {
public:
    int minCost(int i, int j, int n, vector<vector<int>>& triangle){
        vector<int> dp = triangle[n-1];

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i ; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        
        return dp[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        return minCost(0,0,n, triangle);
    }
};