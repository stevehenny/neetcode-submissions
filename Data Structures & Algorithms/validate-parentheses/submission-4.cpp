class Solution {
private:
    bool isOpenParen(char c){
        if(c == '(' || c == '[' || c == '{') return true;
        return false;
    }

    // c1 should be the open paren
    // c2 should be the close paren
    bool isClosedMatch(char c1, char c2){
        if(c1 == '(' && c2 == ')') return true;
        if(c1 == '[' && c2 == ']') return true;
        if(c1 == '{' && c2 == '}') return true;
        return false;
    }
public:
    bool isValid(string s) {
        std::stack<char> st;

        for(int i{}; i < s.length(); ++i){
            if(isOpenParen(s[i])) st.push(s[i]);
            else{
                if(st.empty()) return false;
                if(isClosedMatch(st.top(), s[i])) st.pop();
                else return false;
              
            }
        }


        return st.empty();
    }
};
