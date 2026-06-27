class Solution {
public:
    bool isValid(string s) {
        std::stack<char> q;
        for(int i{}; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                q.push(s[i]);
            }
            else{
                if(q.empty()) return false;
                if((s[i] == ')' && q.top() == '(') || (s[i] == '}' && q.top() == '{') || (s[i] == ']' && q.top() == '[') ){
                    q.pop();
                }
                else{
                    q.push(s[i]);
                }
            }
        }
        return q.empty();
    }
};
