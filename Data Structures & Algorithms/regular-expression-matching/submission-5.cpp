class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        dp[0][0] = true;
        // init all '*' to true
        for(int i{1}; i <= n; ++i){
            if(p[i-1] == '*'){
                dp[i][0] = dp[i-2][0];
            }
        }
       

        for(int i{1}; i <=n; ++i){
            for(int j{1}; j<=m; ++j){
                // std::cout << p[i-1] << '\n';
                if(p[i-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){
                    if(p[i-2] == '.'){
                        dp[i][j] = dp[i-2][j] || (dp[i][j-1]);
                    }
                    else{
                        dp[i][j] =   dp[i-2][j] ||(dp[i][j-1] && (s[j-1] == p[i-2]));
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j-1] && (s[j-1] == p[i-1]);
                }
            }
        }
        
        for(int i{}; i <= n; ++i){
            for(int j{}; j <=m; ++j){
                std::cout << dp[i][j] << ' ';
            }
            std::cout << '\n';
        }
        return dp[n][m];
    }
};
