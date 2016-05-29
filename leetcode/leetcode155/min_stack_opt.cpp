#include <iostream>
#include <cstring>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack(): st_len(0) {
        // memset(st, 0, sizeof(st));
        // memset(st_min, 0, sizeof(st_min));
    }
    
    void push(int x) {
        st[st_len] = x;

        if (st_len == 0) {
            st_min[st_len] = x;
            ++st_len;
            return;
        }
        st_min[st_len] = min(x, st_min[st_len-1]);
        ++st_len;
        return;
    }
    
    void pop() {
        --st_len;
        return;
    }
    
    int top() {
        return st[st_len-1];
    }
    
    int getMin() {
        return st_min[st_len-1];
    }

private:
    static const int maxn = 1e4 + 10;
    int st[maxn], st_min[maxn];
    int st_len;
    // stack<int> st, st_min;
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