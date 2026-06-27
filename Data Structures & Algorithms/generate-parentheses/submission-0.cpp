class Solution {
private:
    void backtrack(vector<string>& ret, int open, int closed, int pairs, string curString){
        if(curString.length() == pairs * 2){
            ret.push_back(curString);
        }

        if(closed < open) backtrack(ret, open, closed + 1,  pairs, curString + ')');
        
        if(open < pairs) backtrack(ret, open + 1, closed, pairs, curString + '(');
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
         backtrack(ret, 0, 0, n, "");
         return ret;
    }
};
