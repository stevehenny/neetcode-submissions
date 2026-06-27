class Solution {
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& seen, vector<int>& perm, int depth){
        if(depth >= nums.size()){
            res.push_back(perm);
            return;
        }

        for(int i{}; i < nums.size(); ++i){
            if(seen[i] == 0){
                seen[i] = 1;
                perm.push_back(nums[i]);
                dfs(res, nums, seen, perm, depth + 1);
                seen[i] = 0;
                perm.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<int> seen(nums.size(), 0);
        dfs(res, nums, seen, perm, 0);
        return res;
    }
};
