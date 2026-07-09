class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n < m) return 0;
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        for(int j{0}; j <= n; ++j){
            dp[0][j] = 1;
        }
        for(int i{1}; i <= m; ++i){
            for(int j{1}; j <= n; ++j){
                dp[i][j] = dp[i][j-1];
                if(s[j-1] == t[i-1]) dp[i][j] += dp[i-1][j-1];
            }
        }

        // debug
        for(int i{}; i <= m; ++i){
            for(int j{}; j <= n; ++j){
                std::cout << dp[i][j] << ' ';
            }
            std::cout << '\n';
        }
       return dp[m][n]; 
    }
};
