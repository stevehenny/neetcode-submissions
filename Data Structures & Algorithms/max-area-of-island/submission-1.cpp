class Solution {
    int m, n;
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& seen, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(!grid[i][j]) return 0;
        if(seen[i][j]) return 0;
        seen[i][j] = 1;
        return 1 + dfs(grid, seen, i + 1, j) + dfs(grid, seen, i - 1, j) + 
        dfs(grid, seen, i, j + 1) + dfs(grid, seen, i, j - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // init seen;
        vector<vector<int>> seen(m, vector<int>(n, 0));
        int ret{};
        
        for(int i{}; i < m; ++i){
            for(int j{}; j < n; ++j){
                if(grid[i][j] && !seen[i][j]){
                    std::cout << "Calling dfs\n";
                    ret = max(ret, dfs(grid, seen, i, j));
                }
            }
        }
        return ret;
    }
};
