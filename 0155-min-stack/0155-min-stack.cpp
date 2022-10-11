class MinStack {
public:
    stack<int>main,sub;
    MinStack() {
        sub.push(INT_MAX);
    }
    
    void push(int val) {
        if( val<=sub.top())
            sub.push(val);
        main.push(val);
    }
    
    void pop() {
        if(!sub.empty()&&main.top()==sub.top()) sub.pop();
        if(!main.empty())
        main.pop();
    }
    
    int top() {
        if(!main.empty())
    return main.top();
        return -1;
        }
    
    
    
    int getMin() {
        if(!sub.empty())return sub.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */