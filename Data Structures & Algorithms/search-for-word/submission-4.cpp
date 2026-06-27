class Solution {
private:
    int m;
    int n;
    bool dfs(vector<vector<char>>& board, vector<vector<int>> seen, string& word, int idx, int i, int j){
        
        // bounds check
        if(i < 0 || i >= m || j < 0 || j >= n) return false;

        if(seen[i][j]) return false;

        // we have a match
        if(idx == word.length() - 1 && word[idx] == board[i][j]) return true;
        
        // word does not match
        if(word[idx] != board[i][j]) return false;

        

        // otherwise, continue recursing
        seen[i][j] = 1;
        return dfs(board, seen, word, idx + 1, i + 1, j) || dfs(board,seen, word, idx + 1, i -1, j) || 
        dfs(board,seen, word, idx + 1, i, j + 1) || dfs(board,seen, word, idx + 1, i, j - 1);

        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ret = false;
        m = board.size();
        n = board[0].size();
        vector<vector<int>> seen(m, vector<int>(n, 0));
        for(int i{}; i < m; ++i){
            for(int j{}; j < n; ++j){
                if(board[i][j] == word[0] && !seen[i][j]) ret |= dfs(board,seen, word, 0, i, j);
            }
        }


        return ret;
    }
};
