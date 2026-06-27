class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n{nums.size()};
        std::vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; --i){
            if(i == n - 1) dp[i] = std::max(dp[i+1], nums[i]);
            else dp[i] = std::max(dp[i+1], nums[i] + dp[i+2]);
        }


        return dp[0];
    }
};
