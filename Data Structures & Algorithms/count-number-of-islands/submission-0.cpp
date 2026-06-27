class Solution {
private:
    int m,n;
    vector<vector<int>> seen;

    // dfs only purpose is traverse grid and mark seen on 1s 
    // connected to inital 1 starting point so there are no
    // duplicates
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n) return;

        if(grid[i][j] == '0') return;
        if(seen[i][j]) return;
        seen[i][j] = 1;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i , j +1);
        dfs(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // m x n grid
        m = grid.size();
        n = grid[0].size();
        int count{};
        // init seen;
        for(int i{}; i < m; ++i){
            vector<int> temp;
            for(int j{}; j < n; ++j){
                temp.push_back(0);
            }
            seen.push_back(temp);
        }
        
        int seen_m = seen.size();
        int seen_n = seen[0].size();
        std::cout << seen_m << ' ' << m << '\n';
        std::cout << seen_n << ' ' << n << '\n';
        for(int i{}; i < m; ++i){
            for(int j{}; j < n; ++j){
                if(grid[i][j] == '1' && !seen[i][j]){
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;

    }
};
