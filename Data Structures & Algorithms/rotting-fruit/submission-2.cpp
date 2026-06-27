class Solution {
    int m;
    int n;
    void printGrid(vector<vector<int>>& grid){
        std::cout << '\n';
        for(int i{}; i < m; ++i){
            for(int j{}; j < n; ++j){
                std::cout << grid[i][j] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        

        // looks like a bfs

        // if in an iteration we get 0 new affected fruits, 
        // we want to break and return -1, because it is 
        // impossible to make all the fruit left rotten


        // Should start with a count of fresh fruit left, so 
        // we can know when to break our outer loop

        // While we loop, keep track of how many iterations (minites)
        // it takes to make all the fruit rotten

        std::queue<std::pair<int, int>> rottenFruit; // stores coordinates
        int freshFruit{};
        m = grid.size();
        n = grid[0].size();
        int time{};
        // figure out init state
        for(int i{}; i < m; ++i){
            for(int j{}; j < n; ++j){
                if(grid[i][j] == 2) rottenFruit.push({i, j});
                else if(grid[i][j] == 1) freshFruit++;
            }
        }
       if(freshFruit == 0) return 0;
        while(!rottenFruit.empty()){

            ++time;
            int length = rottenFruit.size();
            for(int i{}; i < length; ++i){
                
                auto p = rottenFruit.front();
                rottenFruit.pop();
                

                // if not bottom row, we can check bellow
                if(p.first + 1 <= m - 1){
                    if(grid[p.first + 1][p.second] == 1) {
                        rottenFruit.push({p.first + 1, p.second});
                        grid[p.first + 1][p.second] = 2;
                        freshFruit--;
                        }
                }

                // if not on top row, check above
                if(p.first - 1 >= 0){
                    if(grid[p.first - 1][p.second] == 1){
                        rottenFruit.push({p.first - 1, p.second});
                        grid[p.first - 1][p.second] = 2;
                        freshFruit--;
                    }
                }

                // if not leftmost column, check to left
                if(p.second - 1 >= 0){
                    if(grid[p.first][p.second - 1] == 1){
                        rottenFruit.push({p.first, p.second - 1});
                        grid[p.first][p.second - 1] = 2;
                        freshFruit--;
                    }
                }

                // if not rightmost column, check to right
                if(p.second + 1 <= n -1){
                    if(grid[p.first][p.second + 1] == 1){
                        rottenFruit.push({p.first, p.second + 1});
                        grid[p.first][p.second + 1] = 2;
                        freshFruit--;
                    }
                }
            }
        }
        return (freshFruit) ? -1 : time-1;
    }
};
