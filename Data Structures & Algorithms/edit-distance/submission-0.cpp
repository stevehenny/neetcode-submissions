class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

        // init first row and col
        for(int i{1}; i <= n; ++i){
            dp[i][0] = dp[i-1][0] + 1;
        }

        for(int j{1}; j <= m; ++j){
            dp[0][j] = dp[0][j-1] + 1;
        }

        // edit dist algo
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= m; ++j){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = std::min({dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1});
                else dp[i][j] = std::min({dp[i-1][j-1] + 1,dp[i-1][j] + 1, dp[i][j-1] + 1});
            }
        }
      
        return dp[n][m];
    }
};
