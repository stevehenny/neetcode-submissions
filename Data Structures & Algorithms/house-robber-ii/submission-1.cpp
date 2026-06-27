class Solution {
private:
    int _helper(vector<int> nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(dp[0], nums[1]);

        for(int i = 2; i < n; ++i){
            dp[i] = std::max(dp[i-1], nums[i]+ dp[i-2]);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
       if(nums.size() == 1) return nums[0]; 
       return std::max(_helper(vector<int>(nums.begin() + 1, nums.end())),
                        _helper(vector<int>(nums.begin(), nums.end() - 1)));
    }
};
