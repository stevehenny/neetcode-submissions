class Solution {
   public:
    string longestPalindrome(string s) {
        size_t n = s.length();
        std::vector<std::vector<bool>> dp(n+1, std::vector<bool>(n+1, false));
        int start_ind{};
        int max_len{};
        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j <= n-1; ++j){
                if(s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(j - i + 1 > max_len){
                        max_len = j - i + 1;
                        start_ind = i;
                    }
                }
            }
        }
        return s.substr(start_ind, max_len);
    }
};
