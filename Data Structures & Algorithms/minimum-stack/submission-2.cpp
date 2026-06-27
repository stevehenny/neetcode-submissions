class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;
    int curMin;
public:
    MinStack() {
        curMin = INT_MAX;
    }
    
    void push(int val) {
        mainStack.push(val);
        curMin = min(curMin, val);
        minStack.push(curMin);
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
        
        curMin = (minStack.empty()) ? INT_MAX : max(curMin, minStack.top());
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
