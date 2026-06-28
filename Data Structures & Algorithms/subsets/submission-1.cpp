class Solution {
public:
    void getSubsets(std::vector<std::vector<int>>& res, 
                    std::vector<int>& cur_subset,
                    std::vector<int>& nums,
                    int cur_ind){
        if(cur_ind >= nums.size()){
            res.emplace_back(cur_subset);
            return;
        }

        cur_subset.push_back(nums[cur_ind]);
        getSubsets(res, cur_subset, nums, cur_ind + 1);
        cur_subset.pop_back();
        getSubsets(res, cur_subset, nums, cur_ind + 1);
                    }
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur_subset;
        getSubsets(res, cur_subset, nums, 0);
        return res;
    }
};
