class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res;

        int layers = (min(rows, cols) + 1) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            int top = layer;
            int bottom = rows - layer - 1;
            int left = layer;
            int right = cols - layer - 1;

            // left -> right
            for (int j = left; j <= right; ++j)
                res.push_back(matrix[top][j]);

            // top -> bottom
            for (int i = top + 1; i <= bottom; ++i)
                res.push_back(matrix[i][right]);

            // right -> left
            if (top != bottom) {
                for (int j = right - 1; j >= left; --j)
                    res.push_back(matrix[bottom][j]);
            }

            // bottom -> top
            if (left != right) {
                for (int i = bottom - 1; i > top; --i)
                    res.push_back(matrix[i][left]);
            }
        }

        return res;
    }
};