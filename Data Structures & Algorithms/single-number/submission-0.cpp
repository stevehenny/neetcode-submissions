class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int accum{};
        for(int &num: nums){
            accum ^= num;
        }
        return accum;
    }
};
