#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int str2int(string s) {
        bool sig = false;
        if (s[0] == '-') {
            sig = true;
            s = s.substr(1);
        }

        int sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            sum = 10*sum + s[i]-'0';
        }

        return sig ? -sum : sum;
    }

    bool is_op(string s) {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }

    int op_result(int op1, int op2, string op) {
        if (op == "+") return op1+op2;
        else if (op == "-") return op1-op2;
        else if (op == "*") return op1*op2;
        return op1/op2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (is_op(tokens[i])) {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                st.push(op_result(op1, op2, tokens[i]));
            } else {
                st.push(str2int(tokens[i]));
            }
        }
        return st.top();
    }
};

int main() {
    string a[] = {
        "2", "1", "+", "3", "*"
    };
    vector<string> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.evalRPN(v) << endl;
    return 0;
}