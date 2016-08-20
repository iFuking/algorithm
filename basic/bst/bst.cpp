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

    Codec(): null_ptr(-1) {}

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
            s += ',';
        }
        return s.substr(0, s.length()-1);
    }

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

    vector<int> seri(TreeNode* root) {
        vector<int> v; bfs(root, v);
        return v;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> v = seri(root);
        return vec2str(v);
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
        data += ',';

        string s;
        for (int i = 0; i < data.length(); ++i) {
            if (data[i] == ',') {
                v.push_back(str2int(s));
                s = "";
            } else {
                s += data[i];
            }
        }
        return;
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
    
    TreeNode* deseri(vector<int> &data) {
        return bfs1(data);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return NULL;
        }

        vector<int> v; str2vec(data, v);
        return deseri(v);
    }


private:
    int null_ptr;
};


void pre_order(TreeNode *root) {
    if (!root) return;
    cout << root->val << ",";
    pre_order(root->left);
    pre_order(root->right);
    return;
}

void insert_bst(TreeNode *root, int n) {
    if (!root) return;

    if (n < root->val) {
        if (!root->left) {
            root->left = new TreeNode(n);
        } else {
            insert_bst(root->left, n);
        }
    } else {
        if (!root->right) {
            root->right = new TreeNode(n);
        } else {
            insert_bst(root->right, n);
        }
    }
    return;
}

TreeNode* build_bst(vector<int> &v) {
    if (v.size() == 0) {
        return NULL;
    }
    TreeNode *root = new TreeNode(v[0]);
    for (int i = 1; i < v.size(); ++i) {
        insert_bst(root, v[i]);
    }
    return root;
}

TreeNode *ll_rotate(TreeNode *root) {
    TreeNode *p = root->left;
    root->left = p->right;
    p->right = root;
    return p;
}

TreeNode *rr_rotate(TreeNode *root) {
    TreeNode *p = root->right;
    root->right = p->left;
    p->left = root;
    return p;
}


int main() {
    Codec sol;
    string s = "18,14,20,12,16,-1,-1,-1,-1,15,-1";
    TreeNode *r = sol.deserialize(s);
    pre_order(r);
    cout << endl;

    r->left = rr_rotate(r->left);
    r = ll_rotate(r);
    pre_order(r);
    return 0;
}
