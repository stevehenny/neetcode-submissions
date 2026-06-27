class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& candidates, int& target, vector<int>& subset, int curSum, int idx){
        if(curSum == target){
            res.push_back(subset);
            return;
        }
        for(int i = idx; i < candidates.size(); ++i){
            if(i > idx && candidates[i] == candidates[i-1])continue;
            if(curSum > target)break;
            subset.push_back(candidates[i]);
            dfs(res, candidates, target, subset, curSum + candidates[i], i +1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, candidates, target, subset, 0, 0);
        return res;

    }
};
