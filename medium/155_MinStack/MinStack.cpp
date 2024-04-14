class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stackVec.size() == 0) {
            stackVec.push_back(val);
            minVec.push_back(val);
        } else {
            minVec.push_back(min(minVec.back(), val));
            stackVec.push_back(val);
        }
    }
    
    void pop() {
        stackVec.pop_back();
        minVec.pop_back();
    }
    
    int top() {
        return stackVec.back();
    }
    
    int getMin() {
        return minVec.back();
    }
private:
    vector<int> stackVec;
    vector<int> minVec;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */