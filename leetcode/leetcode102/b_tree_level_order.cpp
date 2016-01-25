#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > level_order;
        if (!root) return level_order;

        queue<TreeNode*> q; q.push(root);
        int head = 0, tail = 1, tmp = tail;
        while (!q.empty()) {
            vector<int> level;
            while (head < tail) {
                TreeNode *tree = q.front(); q.pop(); ++head;
                level.push_back(tree->val);
                if (tree->left) { q.push(tree->left); ++tmp; }
                if (tree->right) { q.push(tree->right); ++tmp; }
            }
            level_order.push_back(level);
            tail = tmp;
        }
        return level_order;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    Solution sol;
    sol.levelOrder(root);
    return 0;
}
