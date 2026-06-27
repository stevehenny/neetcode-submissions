class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>&nums, vector<int>& subset, int i){
        // base case
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }
        backtrack(res, nums, subset, i+1);
        subset.push_back(nums[i]);
        backtrack(res, nums, subset, i + 1);
        subset.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        std::vector<int> subset;
        backtrack(res, nums, subset, 0);
        return res;
        
    }
};
