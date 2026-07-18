class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // going to perform a breadth first search
        // pq holds the following -> [cur_cost, i, j]
        priority_queue<tuple<int,int,int>, 
                    vector<tuple<int,int,int>>, 
                    std::greater<>> pq;
        int n = grid.size();
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        vector<vector<int>> dirs = {{0,1}, {0, -1}, {1,0}, {-1,0}};

        pq.push(std::tuple<int,int,int>{grid[0][0],0,0});
        int min_max{INT_MAX};


        
        // this breadth first search can be framed as trying to find the minimum maximum along a given
        // path. Finding the minimum maximum can also be done via a depth first search, dikstra's + binary 
        // search, and union find. Given the input however, breadth first search was the most natural solution

        // The goal of this main loop should be to update min_max whenever we have acheived a path that reaches 
        // grid[n-1][n-1]. We can then prune paths that exceed this min max.
        while(!pq.empty()){
            auto [cur_cost, i, j] = pq.top();
            pq.pop();
            
            if(min_max <= cur_cost) continue;
            // std::cout << "(i,j)->" << "(" << i << ',' << j << ")\n";
            if(i == n-1 && j == n-1){
                min_max = std::min(min_max, cur_cost);
                std::cout << min_max << '\n';
                continue;
            }

            if(seen[i][j]) continue;

            for(auto& dir: dirs){
                int ni = i + dir[0];
                int nj = j + dir[1];

                // bounds check
                if(ni == i && nj == j) continue;
                if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;


                // check whether current cell, is less than min_max. If it isn't continue
                if(min_max <= grid[ni][nj]) continue;
                

                // now explore given path
                pq.push(std::tuple<int,int,int>{std::max(cur_cost, grid[ni][nj]), ni, nj});

            }
            seen[i][j] = true;
        }
        return min_max;
    }
};
