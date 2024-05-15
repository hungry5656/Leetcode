class MyStack {
public:
    MyStack() {
        currIdx = 0;
    }
    
    void push(int x) {
        numQ[currIdx].push(x);
    }
    
    int pop() {
        while (numQ[currIdx].size() > 1) {
            numQ[1 - currIdx].push(numQ[currIdx].front());
            numQ[currIdx].pop();
        }
        int retVal = numQ[currIdx].front();
        numQ[currIdx].pop();
        currIdx = 1 - currIdx;
        return retVal;
    }
    
    int top() {
        while (numQ[currIdx].size() > 1) {
            numQ[1 - currIdx].push(numQ[currIdx].front());
            numQ[currIdx].pop();
        }
        int retVal = numQ[currIdx].front();
        numQ[1 - currIdx].push(retVal);
        numQ[currIdx].pop();
        currIdx = 1 - currIdx;
        return retVal;
    }
    
    bool empty() {
        return numQ[currIdx].empty();
    }
private:
    queue<int> numQ[2];
    int currIdx;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */