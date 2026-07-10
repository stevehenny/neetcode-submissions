class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        dp[0][0] = true;

        // init all '*' -> if '*' set dp[i][j] = 2 chars before
        for(int i{1}; i <= n; ++i){
            if(p[i-1] == '*'){
                dp[i][0] = dp[i-2][0];
            }
        }
       

        for(int i{1}; i <=n; ++i){
            for(int j{1}; j<=m; ++j){
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
        return dp[n][m];
    }
};
