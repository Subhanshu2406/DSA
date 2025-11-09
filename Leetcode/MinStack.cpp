class MinStack {
public:
    std::stack<int> stk;
    std::stack<int> minstk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            minstk.push(val);
        }
        else if(val <= minstk.top()){
            minstk.push(val);
        }
        stk.push(val);
    }
    
    void pop() {
        if(stk.top() == minstk.top()) minstk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
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