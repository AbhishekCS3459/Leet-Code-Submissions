class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int f=q1.front();
            q1.pop();
            q2.push(f);
        }
        std::swap(q1,q2);
    }
    
    int pop() {
        if(q1.empty())return -1;
        else{
            int f=q1.front();
            q1.pop();
            return f;}
    }
    
    int top() {
        if(q1.empty())return -1;
        else
        return q1.front();
        
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */