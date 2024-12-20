// https://leetcode.com/problems/min-stack

class MinStack {
public:
    stack<int> st;
    int minVal = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minVal = val;
        }
        else {
            if(val < minVal) {
                int temp = 2 * val - minVal;
                st.push(temp);
                minVal = val;
            }
            else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        if(st.top() < minVal) {
            int temp = 2 * minVal - st.top();
            minVal = temp;
            st.pop();
        }
        else
            st.pop();
    }
    
    int top() {
        return (st.top() < minVal) ? 2*minVal - st.top() : st.top();
    }
    
    int getMin() {
        return minVal;
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