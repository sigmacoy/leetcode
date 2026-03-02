#include <bits/stdc++.h>

class MinStack {
    stack<int> mainSt, minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainSt.push(val);
        if(minSt.empty() || minSt.top() >= val){
            minSt.push(val);
        }
    }
    
    void pop() {
        if(minSt.top() == mainSt.top()){
            minSt.pop();
        }
        mainSt.pop();
    }
    
    int top() {
        return mainSt.top();
    }
    
    int getMin() {
        return minSt.top();
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