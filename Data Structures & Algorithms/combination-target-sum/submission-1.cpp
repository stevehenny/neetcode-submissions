class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int& target, vector<int>& subset, int curSum, int i){
        if(curSum == target) {
            res.push_back(subset);
            return;
        }
        else if(i >= nums.size() || curSum > target){
            return;
        }
        subset.push_back(nums[i]);
        backtrack(res, nums, target, subset, curSum + nums[i], i);
        subset.pop_back();
        backtrack(res, nums, target, subset, curSum, i + 1);

        

        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(res, nums, target, subset, 0, 0);
        return res;
    }
};
