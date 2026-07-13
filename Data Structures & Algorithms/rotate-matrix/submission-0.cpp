class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i{}; i <= n - 2; ++i){
            for(int j{i}; j < n - i - 1; ++j){
                int prev = matrix[i][j];
                int cur_i = i, cur_j = j;
                for(int k{}; k < 4; ++k){
                    int prev_j = cur_j;
                    cur_j = n - cur_i - 1;
                    cur_i = prev_j;
                    int temp = matrix[cur_i][cur_j];
                    matrix[cur_i][cur_j] = prev;
                    prev = temp;
                }
            }
        }
    }
};
