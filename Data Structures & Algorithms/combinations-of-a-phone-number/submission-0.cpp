class Solution {
private:
    std::unordered_map<char, vector<char>> numMap = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
        };
    
    std::vector<string> res;

    void dfs(std::string& digits, std::string& curString, int curInd){
        if(curInd >= digits.length()){
            res.push_back(curString);
            return;
        }
        for(char c: numMap[digits[curInd]]){
            curString.push_back(c);
            dfs(digits, curString, curInd + 1);
            curString.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        std::string curString;
        if(digits == "") return res;
        dfs(digits, curString, 0);
        return res;
    }
};
