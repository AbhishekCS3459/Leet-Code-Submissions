class MinStack {
public:
    stack<int>s,sp;
    int mn;
    MinStack() {
        mn=INT_MAX;
        
    }
    
    void push(int val) {
              if(sp.empty()|| val<=sp.top())
            sp.push(val);
        s.push(val);
    }
    
    void pop() {
        if(s.empty())return ;
         if(!sp.empty()&&sp.top()==s.top())sp.pop();
        s.pop();
    }
    
    int top() {
        if(s.empty())return -1;
        else
            return s.top();
    }
    
    int getMin() {
        if(s.empty())return -1;
        else
            return sp.top();
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