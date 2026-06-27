class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n{nums.size()};
        if(n == 1) return nums[0];
        std::vector<int> first_rob(n, 0);
        std::vector<int> second_rob(n, 0);
        first_rob[0] = 0;
        first_rob[1] = nums[0];
        second_rob[0] = 0;
        second_rob[1] = nums[1];
        for(int i{2}; i < n; ++i){
            first_rob[i] = std::max(nums[i-1] + first_rob[i-2], first_rob[i-1]);
            second_rob[i] = std::max(nums[i] + second_rob[i-2], second_rob[i-1]);
        }

        return std::max(second_rob[n-1], first_rob[n-1]);


        
    }
};
