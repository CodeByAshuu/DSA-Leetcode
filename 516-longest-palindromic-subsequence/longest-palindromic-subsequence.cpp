class Solution {
public:
    int LCS(int i, int j ,const string &s,const string &rev, vector<vector<int>>&dp){
        if(i == s.size() || j == s.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == rev[j]){
            return dp[i][j] = 1 + LCS(i+1, j+1, s, rev, dp);
        }

        return dp[i][j] = max(
            LCS(i+1, j, s, rev, dp),
            LCS(i, j+1, s, rev, dp)
        );
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return LCS(0,0,s, rev, dp);
    }
};