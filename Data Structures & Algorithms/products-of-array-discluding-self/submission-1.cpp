class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> left(n, 1);
        std::vector<int> right(n, 1);

        for(int i = 1; i < n; ++i){
            left[i] = left[i-1] * nums[i-1];
            right[n-i-1] = right[n-i] * nums[n-i];
        }

        // we've now constructed the left and right product buffers
        // accumulate the products into left and return left
        for(int i = 0; i < n; ++i){
            left[i] *= right[i];
        }
        return left;
    }   
};
