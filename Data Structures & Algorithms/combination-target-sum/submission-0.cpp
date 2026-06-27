class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int& target, vector<int>& subset, int curSum, int start){
        if(curSum == target) {
            res.push_back(subset);
            return;
        }
        else if(curSum > target){
            return;
        }

        for(int i = start; i < nums.size(); ++i){
            if(i > start && nums[i] == nums[i-1]) continue;
            if(curSum + nums[i] > target) break;
            subset.push_back(nums[i]);
            backtrack(res, nums, target, subset, curSum + nums[i], i);
            subset.pop_back();
        }

        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(res, nums, target, subset, 0, 0);
        return res;
    }
};
