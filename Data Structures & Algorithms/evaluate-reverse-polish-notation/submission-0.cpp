class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<string> q;
        // int ret{};
        for(string &s: tokens){
            if(s == "/" || s == "+" || s == "*" || s == "-"){
                int secondOp = stoi(q.top());
                q.pop();
                int firstOp = stoi(q.top());
                q.pop();
                if(s =="/") q.push(std::to_string(firstOp / secondOp));
                else if(s == "*") q.push(std::to_string(firstOp * secondOp));
                else if (s == "+") q.push(std::to_string(firstOp + secondOp));
                else if (s =="-") q.push(std::to_string(firstOp - secondOp));
            }
            else{
                q.push(s);
            }
        }
        return stoi(q.top());
    }
};
