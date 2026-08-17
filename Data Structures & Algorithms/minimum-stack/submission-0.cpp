class MinStack {
public:
    stack<pair<int,int>>stk;
    MinStack() {}
    
    void push(int value) {
        int min = stk.empty() ? value : (value>stk.top().second) ? stk.top().second : value;
        stk.push({value,min});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */