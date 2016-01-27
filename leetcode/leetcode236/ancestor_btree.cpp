#include <iostream>
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
    bool found; vector<int> path;

    void find_node(TreeNode* root, TreeNode* node, vector<int> &p) {
        if (found || !root) return;
        if (root == node) { found = true; path = p; return; }
        if (root->left) { p.push_back(0); find_node(root->left, node, p); p.pop_back(); }
        if (root->right) { p.push_back(1); find_node(root->right, node, p); p.pop_back(); }
        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p==root || q==root) return root;
        vector<int> p_path; found = false; find_node(root, p, p_path); p_path = path;
        vector<int> q_path; found = false; find_node(root, q, q_path); q_path = path;
        for (int i = 0; i<p_path.size() && i<q_path.size(); ++i) {
            if (p_path[i] != q_path[i]) break;
            else if (p_path[i] == 0) root = root->left;
            else root = root->right;
        }
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2), *right = new TreeNode(3);
    left->right = new TreeNode(4);
    root->left = left; root->right = right;
    Solution sol;
    TreeNode *node = sol.lowestCommonAncestor(root, right, left->right);
    cout << node->val << endl;
    return 0;
}
