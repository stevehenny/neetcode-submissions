struct TrieNode{
    std::vector<TrieNode*> nodes = vector<TrieNode*>(26, nullptr);
    bool is_word{false};
};

class Solution {
public:
    void add_word(const string& word){
        TrieNode* temp = _root;
        for(int i{}; i < word.length(); ++i){
            int c = static_cast<int>(word[i] - 'a');
            if(!temp->nodes[c]){
                temp->nodes[c] = new TrieNode();
                temp = temp->nodes[c];
            }
            else{
                temp = temp->nodes[c];
            }
        }
        temp->is_word = true;
    }

    void dfs(vector<vector<char>>& board, TrieNode* node, string& cur_word, int i, int j){
        if(!node) return ;

        if(node->is_word) {
            res.push_back(cur_word);

            // Prevent duplicate insertions
            node->is_word = false;
        }

        char temp = board[i][j];
        board[i][j] = '*';

        for(auto& dir: _dirs){
            int ni = i + dir[0];
            int nj = j + dir[1];

            // out of bounds
            if(ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;

            if(board[ni][nj] == '*') continue;

            int k = board[ni][nj] - 'a';
            
            if(!node->nodes[k]) continue;

            cur_word.push_back(board[ni][nj]);

            dfs(board, node->nodes[k], cur_word, ni, nj);

            cur_word.pop_back();
        }
        board[i][j] = temp;
       

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        _root = new TrieNode();
        n = board.size();
        m = board[0].size();
        for(string& word: words){
            add_word(word);
        }
        // now search
         _root = new TrieNode();

        n = board.size();
        m = board[0].size();

        for(const auto& word : words)
            add_word(word);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int k = board[i][j] - 'a';

                if(!_root->nodes[k])
                    continue;

                std::string cur_word;
                cur_word.push_back(board[i][j]);

                dfs(board,
                    _root->nodes[k],
                    cur_word,
                    i,
                    j);
            }
        }

        return res;
    }
private:
    TrieNode* _root;
    vector<vector<int>> _dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<string> res;
    int n, m;
};
