#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int n): val(n), next(NULL) {}
};

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string name;
        for (int i = 0; i < path.length(); ++i) {
            if (path[i]=='/' && name.length()>0) {
                if (name == ".") ;
                else if (name == "..") {
                    if (!v.empty()) v.pop_back();
                } else v.push_back(name);
                name = "";
            } else if (path[i] != '/') {
                name += path[i];
            }
        }

        if (name.length() > 0) {
            if (name == ".") ;
            else if (name == "..") {
                if (!v.empty()) v.pop_back();
            } else v.push_back(name);
        }

        string simplify_path = "/";
        for (int i = 0; i < v.size(); ++i) {
            simplify_path += v[i];
            simplify_path += '/';
        }

        if (simplify_path == "/") return simplify_path;
        return simplify_path.substr(0, simplify_path.length()-1);
    }
};

int main() {
    Solution sol;
    while (true) {
        string s; cin >> s;
        cout << sol.simplifyPath(s) << endl;
    }
	return 0;
}