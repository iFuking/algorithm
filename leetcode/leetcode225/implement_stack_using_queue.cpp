class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
        return;
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q1.empty()) {
            queue<int> q = q1;
            q1 = q2;
            q2 = q;
        }

        while (true) {
            int ele = q1.front();
            q1.pop();
            if (q1.empty()) {
                return;
            }
            q2.push(ele);
        }
        return;
    }

    // Get the top element.
    int top() {
        if (!q1.empty()) {
            return q1.back();
        }
        return q2.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() & q2.empty();
    }

private:
    queue<int> q1, q2;
};