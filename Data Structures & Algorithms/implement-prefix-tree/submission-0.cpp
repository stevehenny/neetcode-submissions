struct TrieNode{
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        for(int i{}; i < 26; ++i){
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur_char = root;
        int ind;
        for(int i{}; i < word.length(); ++i){
            ind = static_cast<int>(word[i] - 'a');
            if(!cur_char->children[ind]){
                cur_char->children[ind] = new TrieNode();
            }
            cur_char = cur_char->children[ind];
        }
        cur_char->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur_char = root;
        int ind;
        for(int i{}; i < word.length(); ++i){
            ind = static_cast<int>(word[i] - 'a');
            if(!cur_char->children[ind]) return false;

            cur_char = cur_char->children[ind];
        }
        return cur_char->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur_char = root;
        int ind;
        for(int i{}; i < prefix.length(); ++i){
            ind = static_cast<int>(prefix[i] - 'a');
            if(!cur_char->children[ind]) return false;  

            cur_char = cur_char->children[ind];  
        }
        return true;
    }
};
