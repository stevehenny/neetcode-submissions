class Solution {
private:
    int m, n;
    vector<vector<int>> _dirs = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean_flow, int i, int j){
        // don't need to revist  

        for(auto& dir: _dirs){
            int ni = dir[0] + i;
            int nj = dir[1] + j;
            
            if (ni < 0 || ni >= m || nj < 0 || nj >= n){
                continue;
            }
            
            if(ocean_flow[ni][nj]) continue;
            
            if(ocean_flow[i][j] && heights[i][j] <= heights[ni][nj]){
                ocean_flow[ni][nj] = true;
                dfs(heights, ocean_flow, ni, nj);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        std::vector<std::vector<bool>> pacific_flow(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> atlantic_flow(m, std::vector<bool>(n, false));

        // sides
        for(int j{}; j < n; ++j){
            pacific_flow[0][j] = true;
            atlantic_flow[m-1][j] = true;
            dfs(heights, pacific_flow, 0, j);
            dfs(heights, atlantic_flow, m-1, j);
        }

        for(int i{}; i < m; ++i){
            pacific_flow[i][0] = true;
            atlantic_flow[i][n-1] = true;
            dfs(heights, pacific_flow, i, 0);
            dfs(heights, atlantic_flow, i, n-1);
        }

        vector<vector<int>> res;
        for(int i{}; i < m; ++i){
            for(int j{}; j < n; ++j){
                if(pacific_flow[i][j] && atlantic_flow[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;

    }
};
