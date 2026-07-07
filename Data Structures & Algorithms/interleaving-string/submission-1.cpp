class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if(n + m != s3.length()) return false;
        std::vector<std::vector<bool>> dp(n+1, std::vector(m+1, false));

        //init initial rows
        dp[0][0] = true;
        for(int i{1}; i <= n; ++i){
            if(dp[i-1][0] && s1[i-1] == s3[i-1]) dp[i][0] = true; 
        }
        for(int j{1}; j <= m; ++j){
            if(dp[0][j-1] && s2[j-1] == s3[j-1]) dp[0][j] = true;
        }

        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= m; ++j){
                if(dp[i-1][j] && s1[i-1] == s3[i+j-1])
                    dp[i][j] = true; 
                if (dp[i][j-1] && s2[j-1] == s3[i+j-1])
                    dp[i][j] = true; 
            }
        }

        //debug
        for(int i{}; i<=n; ++i){
            for(int j{}; j <=m; ++j){
                std::cout << dp[i][j] << ' ';
            }
            std::cout << '\n';
        }
        return dp[n][m];
        
    }
};
