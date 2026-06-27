class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size() , 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = std::max(nums[i], dp[i-1] + nums[i]);
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

// [2,-3,4,-2,2,1,-1,4]
// curMax = 8
// retMax = 2