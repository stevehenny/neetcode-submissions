struct TrieNode {
    std::vector<TrieNode*> nodes = std::vector<TrieNode*>(26, nullptr);
    bool isWord{false};
};

class WordDictionary {
public:
    WordDictionary() {
        _root = new TrieNode();
    }
    
    void addWord(string word) {
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
        temp->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = _root;
        return dfs(temp, word, 0);
        
    }
private:
    TrieNode* _root;

    bool dfs(TrieNode* cur_node, string& word, int i){
        if(!cur_node) return false;
        if(i >= word.length()){
            if(cur_node->isWord) return true;
            else return false;
        }

        // need to call dfs on all options
        bool ret{false}; 
        if(word[i] == '.'){
            for(int j{}; j < 26; ++j){
                if(cur_node->nodes[j])
                    ret = ret || dfs(cur_node->nodes[j], word, i+1);
            }
            return ret;
        }

        int c = static_cast<int>(word[i] - 'a');
        if(cur_node->nodes[c])
            return ret || dfs(cur_node->nodes[c], word, i+1);
        else return false;
    }
};
