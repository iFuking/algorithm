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

    Codec(): nullp(nullpt) {}

    void seri_pre(TreeNode *root, vector<int> &v) {
        if (!root) {
            v.push_back(nullp);
            return;
        }
        v.push_back(root->val);
        seri_pre(root->left, v);
        seri_pre(root->right, v);
        return;
    }

    string int2str(int n) {
        bool flag = n<0 ? true : false;
        unsigned int un = n<0 ? 0-n : n;
        if (un == 0) return "0";

        string s;
        while (un) {
            s += un%10+'0';
            un /= 10;
        }
        reverse(s.begin(), s.end());
        return flag ? '-'+s : s;
    }

    string to_str(vector<int> &v) {
        string s;
        for (int i = 0; i < v.size()-1; ++i) {
            s += int2str(v[i]);
            s += ',';
        }
        s += int2str(v[v.size()-1]);
        return s;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> v; seri_pre(root, v);
        return to_str(v);
    }


    int str2int(string &s) {
        bool flag = s[0]=='-' ? true : false;
        s = flag ? s.substr(1) : s;
        unsigned int sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            sum = 10*sum + s[i]-'0';
        }
        return flag ? 0-sum : sum;
    }

    vector<int> parse_str(string &data) {
        vector<int> v;
        data += ',';
        string s;
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

    TreeNode *deseri_pre(vector<int> &v, int &index) {
        if (v[index] == nullp) {
            ++index;
            return NULL;
        }
        TreeNode *root = new TreeNode(v[index++]);
        root->left = deseri_pre(v, index);
        root->right = deseri_pre(v, index);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v = parse_str(data);
        int index = 0;
        return deseri_pre(v, index);
    }

    // void preorder_traverse(TreeNode *root) {
    //     if (!root) return;
    //     cout << root->val << ",";
    //     preorder_traverse(root->left);
    //     preorder_traverse(root->right);
    //     return;
    // }

private:
    static const int nullpt = 0x3f3f3f3f;
    int nullp;
};

int main() {
    Codec sol;
    string s = "1,2,-1,-1,3,4,-1,-1,5,-1,-1";

    TreeNode *root = sol.deserialize(s);
    // sol.preorder_traverse(root);
    cout << sol.serialize(root) << endl;
    return 0;
}