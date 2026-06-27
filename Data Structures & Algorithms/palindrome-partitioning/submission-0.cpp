class Solution {
private:
    bool isPalindrome(string& s){
        int l{}; 
        int r = s.length() - 1;

        while(l <= r){
            // std::cout << r << " " << l << '\n';
            if(s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
    vector<vector<string>> res;
    void dfs(string& s, vector<string>& curPartition, int curInd){
        if (curInd >= s.length() - 1){
            res.push_back(curPartition);
            return;
        }
        string curString;
        for(int i{curInd + 1}; i < s.length(); ++i){
            curString += s[i];
            if(isPalindrome(curString)){
                curPartition.push_back(curString);
                dfs(s, curPartition, i);
                curPartition.pop_back();
            }
        }


    }
public:
    vector<vector<string>> partition(string s) {
        
        vector<string> curPartition;
        string curString;
        for(int i{}; i < s.length(); ++i){
            curString += s[i];
            if(isPalindrome(curString)){
                curPartition.push_back(curString);
                dfs(s, curPartition, i);
                curPartition.pop_back();
            }
        }
        
        return res;
    }
};
