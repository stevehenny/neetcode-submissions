class Solution {
private:
    int _global_max{0};
    int n,m;
    vector<vector<int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp,
            int i, int j, int previous){
            if(i < 0 || i >= n || j < 0 || j>= m || matrix[i][j] <= previous) return 0;
            
            if(dp[i][j] != -1) return dp[i][j];
            
            int res{1};
            for(auto& dir: directions){
                res = std::max(res, 1 + dfs(matrix, dp, i+dir[0], j+dir[1], matrix[i][j]));
            }
            dp[i][j] = res;
            return res;

        }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m,-1));
        for(int i{}; i < n; ++i){
            for(int j{}; j < m; ++j){
                _global_max = std::max(_global_max, dfs(matrix, dp, i, j, INT_MIN));
            }
        }

        return _global_max;
    }
};
