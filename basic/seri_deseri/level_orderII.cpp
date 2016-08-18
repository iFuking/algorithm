#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    Codec(): null_ptr(0x3f3f3f3f) {}

    void bfs(TreeNode *root, vector<int> &v) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if (!node) {
                v.push_back(null_ptr);
                continue;
            }

            v.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }

        while (v.size()>2 && v[v.size()-1]==null_ptr && v[v.size()-2]==null_ptr) {
            v.pop_back();
            v.pop_back();
        }
        return;
    }

    long long llabs(long long n) {
        return n>0 ? n : 0-n;
    }

    string int2str(int n) {
        if (n == 0) return "0";

        bool sig = false;
        if (n < 0) {
            sig = true;
        }

        long long lln = llabs(n);
        string s;
        while (lln) {
            s += (lln%10 + '0');
            lln /= 10;
        }
        reverse(s.begin(), s.end());
        if (sig) {
            return '-'+s;
        }
        return s;
    }

    string vec2str(vector<int> &v) {
        string s;
        for (int i = 0; i < v.size(); ++i) {
            s += int2str(v[i]);
            s += '#';
        }
        return s.substr(0, s.length()-1);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> v = seri(root);
        return vec2str(v);
    }

    vector<int> seri(TreeNode* root) {
        vector<int> v; bfs(root, v);
        return v;
    }


    TreeNode* bfs1(vector<int> &v) {
        if (v.size() == 0) return NULL;

        TreeNode *root = new TreeNode(v[0]);
        queue<TreeNode*> q;
        q.push(root);

        int index = 1;
        while (!q.empty() && index<v.size()) {
            TreeNode *node = q.front(); q.pop();
            if (!node) continue;

            node->left = v[index]==null_ptr ? NULL : new TreeNode(v[index]);
            q.push(node->left);
            ++index;
            node->right = v[index]==null_ptr ? NULL : new TreeNode(v[index]);
            q.push(node->right);
            ++index;
        }
        return root;
    }


    int str2int(string &s) {
        bool sig = false;
        if (s[0] == '-') {
            sig = true;
            s = s.substr(1);
        }

        long long n = 0;
        for (int i = 0; i < s.length(); ++i) {
            n = 10*n+s[i]-'0';
        }

        if (sig) {
            n = 0-n;
        }
        return (int)n;
    }

    void str2vec(string &data, vector<int> &v) {
        data += '#';

        string s;
        for (int i = 0; i < data.length(); ++i) {
            if (data[i] == '#') {
                v.push_back(str2int(s));
                s = "";
            } else {
                s += data[i];
            }
        }
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return NULL;
        }

        vector<int> v; str2vec(data, v);
        return deseri(v);
    }

    TreeNode* deseri(vector<int> &data) {
        return bfs1(data);
    }

private:
    int null_ptr;
};


int main() {
    Codec sol;
    string s = "-1#0#1";
    TreeNode *r = sol.deserialize(s);
    string s1 = sol.serialize(r);
    cout << s1 << endl;
    return 0;
}

