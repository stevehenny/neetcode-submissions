class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res;

        int layers = (min(rows, cols) + 1) / 2;
        int top = 0, bottom = rows;
        int left = 0, right = cols;
        while(top < bottom && left < right){
            for(int j{left}; j < right; ++j){
                res.push_back(matrix[top][j]);
            }
            ++top;

            for(int i{top}; i < bottom; ++i){
                res.push_back(matrix[i][right-1]);
            }
            --right;

            if (!(left < right && top < bottom)) break;
         
            for(int j{right-1}; j >= left; --j){
                res.push_back(matrix[bottom-1][j]);
            }
            --bottom;

            for(int i{bottom-1}; i >= top; --i){
                res.push_back(matrix[i][left]);
            }
            ++left;
        }

       

        return res;
    }
};