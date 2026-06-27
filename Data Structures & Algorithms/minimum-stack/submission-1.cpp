class MinStack {
private:
    int curMin = INT_MAX;
    std::stack<int> q;
    std::stack<int> prefix;
public:
    MinStack() {
    }
    
    void push(int val) {
        q.push(val);
        if(prefix.empty()){
            prefix.push(val);
        }
        else{
            prefix.push(min(val, prefix.top()));
        }
        // curMin = std::min(val, curMin);
        // prefix.push(curMin);
        // cout <<curMin;
    }
    
    void pop() {
        q.pop();
        prefix.pop();
  

    }
    
    int top() {
        return q.top();
    }
    
    int getMin() {
        return prefix.top();
    }
};
