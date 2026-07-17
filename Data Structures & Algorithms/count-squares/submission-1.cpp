class CountSquares {
public:
    CountSquares() {
        _grid = vector<vector<int>>(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        ++_grid[x][y];
        
       
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int count{};
        for(int i{}; i < 4; ++i){
            int dir_mult_x = _dir[i][0];
            int dir_mult_y = _dir[i][1];
            for(int d{1}; d < 1001; ++d){
                int x_dir = dir_mult_x * d + x;
                int y_dir = dir_mult_y * d + y;

                if(x_dir < 0 || x_dir >= 1001 || y_dir < 0 || y_dir >= 1001){
                    continue;
                }

                count += (_grid[x_dir][y_dir] * _grid[x_dir][y] * _grid[x][y_dir]);
                    
            }
        }
        return count;
    }
private:
    vector<vector<int>> _grid;
    vector<vector<int>> _dir = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};

};
