class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
    
// use two stacks to reverse
       while(!s1.empty()){
           int t=s1.top();
           s1.pop();
           s2.push(t);
       }
        s1.push(x);
               while(!s2.empty()){
           int t=s2.top();
           s2.pop();
           s1.push(t);
       }
    }
    
    int pop() {
        if(s1.empty())return -1;
        else
        {
            int top=s1.top();
            s1.pop();
            return top;
        }
    }
    
    int peek() {
        if(s1.empty())return -1;
        else
            return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */