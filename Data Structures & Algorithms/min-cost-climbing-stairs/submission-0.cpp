class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t n{cost.size()};
        std::vector<int> dp(n+1, 0);
        
        dp[n] = 0;
        dp[n-1] = cost[n-1];
        for(int i = n-2; i >= 0; --i){
            dp[i] = std::min(dp[i+1] + cost[i], dp[i+2] + cost[i]);
        }

        return std::min(dp[0], dp[1]);
    }
};