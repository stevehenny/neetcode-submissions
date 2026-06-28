class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        std::vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i{n-1}; i >= 0; --i){
            // special boundary case
            if(i == n-1){
                if(s[i] == '0') continue;
                dp[i] = 1;
            }

            else{
                if((s[i] == '2' && s[i+1] < '7') || (s[i] == '1')){
                    dp[i] = dp[i+1] + dp[i+2];
                }
                else if(s[i] == '0'){
                    dp[i] = 0;
                }
                else{
                    dp[i] = dp[i+1];
                }
            }
        std::cout << dp[i] << '\n';
            
        }
        return dp[0];
    }
};
