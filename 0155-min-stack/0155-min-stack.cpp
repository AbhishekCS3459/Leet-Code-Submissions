class MinStack {
public:
   long long mn;
    stack<long long>s;
    MinStack() {
     
    }
    // concept : we will create the encryption for the minimum element every time
    void push(int val) {
        if(s.empty()){

            s.push(val);
                        mn=val;
        }

        else{
                     if(val>mn)s.push(val);
            else{
                
            long long int encryption=(2ll* val)-mn;
            mn=val;
        
s.push(encryption);
            
            }
            
        }
         
    }
    
    void pop() {
        if(s.empty())return ;
        if(s.top()>=mn)s.pop();
        else{
            mn=2*mn-s.top();
            s.pop();
            
        }
        }
    
    int top() {
        if(s.top()<mn){
            return mn;
        }
            return s.top();
        
    }
    
    int getMin() {
        return mn;
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