#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Codec {
public:

    Codec(): nullp(0x3f3f3f3f) {}

    string int2str(int n) {
        bool flag = n>0 ? false : true;
        unsigned int un = flag ? 0-n : n;

        if (un == 0) return "0";
        string s;
        while (un) {
            s += un%10+'0';
            un /= 10;
        }
        reverse(s.begin(), s.end());
        return flag ? '-'+s : s;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (!node) {
                v.push_back(nullp);
                continue;
            }

            v.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }

        for (int i = v.size()-1; i >= 0; --i) {
            if (v[i] == nullp) v.pop_back();
            else break;
        }

        if (v.size() == 0) return "";

        string s;
        for (int i = 0; i < v.size()-1; ++i) {
            s += int2str(v[i]);
            s += ',';
        }
        s += int2str(v[v.size()-1]);

        return s;
    }


    int str2int(string &s) {
        bool flag = s[0]=='-' ? true : false;
        s = flag ? s.substr(1) : s;
        unsigned int sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            sum = 10*sum + s[i]-'0';
        }
        return flag ? 0-sum: sum;
    }

    vector<int> parse_data(string &data) {
        data += ',';

        string s;
        vector<int> v;

        for (int i = 0; i < data.length(); ++i) {
            if (data[i] == ',') {
                if (s.length() > 0) {
                    v.push_back(str2int(s));
                }
                s = "";
                continue;
            }
            s += data[i];
        }
        return v;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v = parse_data(data);
        if (v.size() == 0) return NULL;
        TreeNode *root = new TreeNode(v[0]);

        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i<v.size()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) continue;

            node->left = v[i]!=nullp ? new TreeNode(v[i]) : NULL;
            q.push(node->left);
            ++i;
            if (i == v.size()) break;

            node->right = v[i]!=nullp ? new TreeNode(v[i]) : NULL;
            q.push(node->right);
            ++i;
        }

        return root;
    }

private:
    int nullp;
};

int main() {
    Codec sol;
    while (true) {
        string s = "1,-1,2,-2"; // cin >> s;

        TreeNode *root = sol.deserialize(s);
        cout << sol.serialize(root) << endl;
        break;
    }
    return 0;
}