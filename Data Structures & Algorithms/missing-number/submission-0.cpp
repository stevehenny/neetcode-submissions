class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t arraySum{};
        size_t n{nums.size()};
        for(int num: nums){
            arraySum += num;
        }
        return ((n + 1) * n) / 2 - arraySum;
    }
};
