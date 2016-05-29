#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);

        if (st_min.empty()) {
            st_min.push(x);
            return;
        }
        st_min.push(min(x, st_min.top()));
        return;
    }
    
    void pop() {
        st.pop();
        st_min.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st_min.top();
    }

private:
    stack<int> st, st_min;
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}