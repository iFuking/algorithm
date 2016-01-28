#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// this is level order
// no need to follow this format
// just serialize/deserialize correctly is ok
// use preorder traverse
//class Codec {
//public:
//    int M;
//
//    long long labs(long long n) {
//        return n > 0 ? n : 0-n;
//    }
//
//    string int2str(int n) {
//        long long long_n = n;
//        bool flag = long_n<0 ? true : false;
//
//        long_n = labs(long_n);
//        string s;
//        while (long_n) {
//            s += long_n%10+'0';
//            long_n /= 10;
//        }
//        for (int i = 0; i < s.length()/2; ++i) swap(s[i], s[s.length()-1-i]);
//        if (flag) s = "-"+s;
//        return s;
//    }
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        if (!root) return "[]";
//        M = 10000007;
//        vector<int> value; value.push_back(root->val);
//        queue<TreeNode*> q; q.push(root);
//        int head = 0, tail = 1, tmp = tail;
//        while (!q.empty()) {
//            while (head < tail) {
//                TreeNode* node = q.front(); q.pop(); ++head; ++tmp;
//                if (node->left) { q.push(node->left); value.push_back(node->left->val); }
//                else value.push_back(M);
//                if (node->right) { q.push(node->right); value.push_back(node->right->val); }
//                else value.push_back(M);
//            }
//            tail = tmp;
//        }
//
//        int value_size = value.size();
//        for (int i = value_size-1; i >= 0; --i) {
//            if (value[i] == M) --value_size;
//            else break;
//        }
//
//        string seri = "[";
//        for (int i = 0; i < value_size-1; ++i) {
//            if (value[i] == M) seri += "null";
//            else seri += int2str(value[i]);
//            seri += ',';
//        }
//        seri += int2str(value[value_size-1]); seri += ']';
//        return seri;
//    }
//
//    void parse_data(string &data, queue<string> &resp) {
//        string s;
//        for (int i = 1; i < data.length()-1; ++i) {
//            if (data[i] == ',') { resp.push(s); s = ""; }
//            else s += data[i];
//        }
//        if (s.length() > 0) resp.push(s);
//        return;
//    }
//
//    TreeNode *preorder_build_tree(queue<string> &q) {
//        if (q.empty()) return NULL;
//        string s = q.front(); q.pop();
//        TreeNode *root = NULL;
//        if (s == "null") return root;
//        root = new TreeNode(atoi(s.c_str()));
//        root->left = preorder_build_tree(q);
//        root->right = preorder_build_tree(q);
//        return root;
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        queue<string> q; parse_data(data, q);
//        return preorder_build_tree(q);
//    }
//};

class Codec {
public:
    long long labs(long long n) {
        return n > 0 ? n : 0-n;
    }

    string int2str(int n) {
        long long long_n = n;
        bool flag = long_n<0 ? true : false;

        long_n = labs(long_n);
        string s;
        while (long_n) {
            s += long_n%10+'0';
            long_n /= 10;
        }
        for (int i = 0; i < s.length()/2; ++i) swap(s[i], s[s.length()-1-i]);
        if (flag) s = "-"+s;
        return s;
    }

    void seri(TreeNode* root, string &data) {
        if (!root) { data += "#,"; return; }
        data += int2str(root->val); data += ',';
        seri(root->left, data);
        seri(root->right, data);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string seri_root = "["; seri(root, seri_root);
        seri_root += ']';
        return seri_root;
    }

    void parse_data(const string &data, queue<string> &resp) {
        string s;
        for (int i = 1; i < data.length()-1; ++i) {
            if (data[i] == ',') { resp.push(s); s = ""; }
            else s += data[i];
        }
        return;
    }

    TreeNode* deseri(queue<string> &q) {
        TreeNode *root = NULL;
        if (q.empty()) return NULL;
        string s = q.front(); q.pop();
        if (s == "#") return NULL;
        root = new TreeNode(atoi(s.c_str()));
        root->left = deseri(q); root->right = deseri(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q; parse_data(data, q);
        return deseri(q);
    }
};

int main()
{
//    TreeNode *root = new TreeNode(1);
//    TreeNode *left = new TreeNode(2);
//    TreeNode *right = new TreeNode(3);
//    // right->left = new TreeNode(0x7fffffff); right->right = new TreeNode(0x3f3f3f3f);
//    root->left = left; root->right = right;
//    Codec sol;
//    cout << sol.serialize(root) << endl;

    string data = "[1,2,#,#,3,#,#]";
    Codec sol;
    TreeNode *root = sol.deserialize(data);
    cout << root->val << ", " << root->left->val << ", " << root->right->val << endl;
    return 0;
}
