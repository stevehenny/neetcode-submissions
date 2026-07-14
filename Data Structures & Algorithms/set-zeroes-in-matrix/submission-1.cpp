class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<bool> rowZero(rows, false);
        std::vector<bool> colZero(cols, false);

        for(int i{}; i < rows; ++i){
            for(int j{}; j < cols; ++j){
                if(matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }

        // iterate through rows
        for(int i{}; i < rows; ++i){
            if(rowZero[i]){
                for(int j{}; j < cols; ++j){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j{}; j < cols; ++j){
            if(colZero[j]){
                for(int i{}; i < rows; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
