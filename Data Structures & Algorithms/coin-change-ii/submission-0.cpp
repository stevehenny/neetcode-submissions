class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(amount+1, 0));

        // for each coin, there is exactly one way to get to 0
        for(int i{}; i < n; ++i){
            dp[i][amount] = 1;
        }

        // now perform bottom up approach:
        for(int i{n-1}; i >= 0; --i){
            for(int j{amount - 1}; j>=0; --j){
                if(j + coins[i] <= amount)
                    dp[i][j] = dp[i][j + coins[i]];
                if(i + 1 < n)
                    dp[i][j] += dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};
