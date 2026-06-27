class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = n - 2; i >= 0; --i){
            if(nums[i] == 0) dp[i] = INT_MAX;
            else if(nums[i] + i < n) dp[i] = dp[nums[i] + i] + 1;
            else dp[i] = dp[n-1] + 1;

            dp[i] = std::min(dp[i], dp[i + 1] + 1);
        } 
        return dp[0];
    }
};
