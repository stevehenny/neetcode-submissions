class Solution {
public:
    bool dfs(std::vector<std::vector<bool>>& dp, int row, int col, int n, std::vector<int>& memo){
        if(row > n-1) return true;
        if(memo[row] != -1) return memo[row];
        
        for(int j{col}; j < n; ++j){
            if(dp[row][j]) {
                if(dfs(dp, j+1, j+1, n, memo)) return (memo[row] = 1);
            }
        }

        return (memo[row] = 0);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        //create a set for wordDict
        std::unordered_set<string> wordSet;
        for(string& str: wordDict){
            wordSet.insert(str);
        }

        for(int i{}; i < n; ++i){
            string cur_str;
            for(int j{i}; j < n; ++j){
                cur_str += s[j];
                if(wordSet.count(cur_str)) dp[i][j] = true;
            }
        }

        std::vector<int> memo(n + 1, -1);
        for(int j{}; j < n; ++j){
            if(dp[0][j]){
                if(dfs(dp, j+1, j+1, n, memo)) return true;
            }
        }

        return false;
    }
};