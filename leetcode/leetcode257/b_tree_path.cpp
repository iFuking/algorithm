#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> path;

    string int2str(int n) {
        long long ln = n;
        bool flag = false;
        if (ln < 0) { flag = true; ln = abs(ln); }
        string strn;
        while (ln) {
            strn += (ln%10)+'0';
            ln /= 10;
        }

        for (int i = 0; i < strn.length()/2; ++i) {
            swap(strn[i], strn[strn.length()-1-i]);
        }
        if (flag) strn = "-"+strn;
        return strn;
    }

    void vec2str(vector<int> &vec) {
        string str = int2str(vec[0]);
        for (int i = 1; i < vec.size(); ++i) {
            str += "->"; str += int2str(vec[i]);
        }
        path.push_back(str);
        return;
    }

    void dfs(TreeNode* root, vector<int> &vec) {
        if (!root) return;
        vec.push_back(root->val);
        if (!root->left && !root->right) vec2str(vec);
        if (root->left) dfs(root->left, vec);
        if (root->right) dfs(root->right, vec);
        vec.pop_back();
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> vec; dfs(root, vec);
        return path;
    }
};

int main()
{
    TreeNode *root = new TreeNode(-1);
    root->left = new TreeNode(2); root->right = new TreeNode(-3);
    Solution sol;
    vector<string> v = sol.binaryTreePaths(root);
    for (int i = 0; i < v.size(); ++i) cout << v[i] << endl;
    return 0;
}
