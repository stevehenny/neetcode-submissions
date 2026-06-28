class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        std::unordered_set<int> num_set{};
        num_set.insert(nums[0]);
        for(int i{1}; i < nums.size(); ++i){
            for(int num: num_set){
                num_set.insert(num + nums[i]);
            }
            if(num_set.count(target)) return true;
        }

        
        



        return false;
    }
};
