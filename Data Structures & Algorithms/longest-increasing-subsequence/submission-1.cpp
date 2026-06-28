class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);

        for(int i{0}; i < n; ++i){
            for(int j{i+1}; j < n; ++j){
                if(nums[j] > nums[i]) dp[j] = std::max(dp[j], dp[i] + 1);
            }
        }
   
        return std::ranges::max(dp);
    }
};
