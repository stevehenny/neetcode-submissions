class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for(string &s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                if(s == "+") st.push(op1 + op2);
                else if(s == "-") st.push(op2 - op1);
                else if(s == "*") st.push(op1 * op2);
                else if(s == "/") st.push(op2 / op1);
                else throw std::runtime_error("Unrecognized operator");
            }
            else{
                st.push(std::atoi(s.c_str()));
            }
        }
        return st.top();
    }
};
