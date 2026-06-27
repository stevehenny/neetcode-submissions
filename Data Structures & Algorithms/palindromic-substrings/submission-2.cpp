class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int total_count{};
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(n+1, false));
        for(int i{n-1}; i >= 0; --i){
            for(int j{i}; j <= n-1; ++j){
                if(s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    ++total_count;
                }
               
            }
        }
       
        return total_count;
    }
};
