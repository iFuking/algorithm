#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int str2int(const string &s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) ans = 10*ans+s[i]-'0';
        return ans;
    }

    int calculate(string s) {
        stack<char> st_op; vector<string> post_fix;
        string num, null_str;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i]>='0' && s[i]<='9') { num += s[i]; continue; }
            if (num.length() > 0) post_fix.push_back(num);
            if (s[i]=='+' || s[i]=='-') {
                if (!st_op.empty()) {
                    char op = st_op.top();
                    if (op != '(') {
                        st_op.pop();
                        post_fix.push_back(op+null_str);
                    }
                }
                st_op.push(s[i]);
            } else if (s[i] == '(') { st_op.push(s[i]);
            } else if (s[i] == ')') {
                while (true) {
                    char op = st_op.top(); st_op.pop();
                    if (op == '(') break;
                    post_fix.push_back(op+null_str);
                }
            }
            num = "";
        }
        if (num.length() > 0) post_fix.push_back(num);
        while (!st_op.empty()) {
            char op = st_op.top(); st_op.pop();
            post_fix.push_back(op+null_str);
        }

        stack<int> st;
        for (int i = 0; i < post_fix.size(); ++i) {
            char ch = post_fix[i][0];
            if (ch>='0' && ch<='9') {
                st.push(str2int(post_fix[i]));
            } else {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                st.push(ch=='+'?op1+op2:op1-op2);
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    while (true) {
        string s; cin >> s;
        cout << sol.calculate("2-(1-2)") << endl;
    }
    return 0;
}
