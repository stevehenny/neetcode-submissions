class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        // no path will ever result in target
        if(std::abs(sum) < std::abs(target)) return 0;
        int n = nums.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(sum * 2 + 1, 0));
        ++dp[0][sum - nums[0]];
        ++dp[0][sum + nums[0]];
    
        for(int i{1}; i < n; ++i){
            for(int j{}; j < sum * 2 + 1; ++j){
                // just check one bound, 0 <= nums[i] <= 1000
                if(j - nums[i] >= 0)
                    dp[i][j] += dp[i-1][j-nums[i]];
                if (j + nums[i] <= sum * 2)
                    dp[i][j] += dp[i-1][j+nums[i]];
            }
           
        }
  
        return dp[n-1][sum + target];
    }

};
