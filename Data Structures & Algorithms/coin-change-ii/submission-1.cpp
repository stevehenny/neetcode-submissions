class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        std::vector<int> dp(amount + 1, 0);

        dp[amount] = 1;
        for(int i{n-1}; i >= 0; --i){
            for(int j{amount-1}; j >= 0; --j){
                if(j + coins[i] <= amount)
                    dp[j] += dp[j + coins[i]];
            }
        }
        return dp[0];

        
    }
};
