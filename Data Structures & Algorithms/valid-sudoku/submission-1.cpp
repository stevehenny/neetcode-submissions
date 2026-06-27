namespace std{
    template<typename T1, typename T2>
    struct hash<std::pair<T1,T2>>{
        
        size_t operator()(const std::pair<T1, T2>& p) const{

            size_t h1 = std::hash<T1>{}(p.first);
            size_t h2 = std::hash<T2>{}(p.second);

            return h1 ^ (h2 << 1);
        }
    };
    
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        unordered_map<pair<int, int>, unordered_set<char>> threes;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                std::pair pairKey = {i / 3, j / 3};

                if(rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || threes[pairKey].count(board[i][j])){
                    return false;
                }
                
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                threes[pairKey].insert(board[i][j]);
                

                
            }
        
        }
        return true;

    }
};
