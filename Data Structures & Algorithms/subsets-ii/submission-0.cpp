class Solution {
std::unordered_map<int, int> hashMap;
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& subset, int i){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(res, nums, subset, i + 1);
        subset.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1]) ++i;

        dfs(res, nums, subset, i + 1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, nums, subset, 0);
        return res;

    }
};
