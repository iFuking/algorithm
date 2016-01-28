#include <iostream>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (!root) return v;
        queue<TreeNode*> q; q.push(root);
        int head = 0, tail = 1, tmp = tail;
        while (!q.empty()) {
            int right_most;
            while (head < tail) {
                TreeNode *node = q.front(); q.pop(); ++head;
                right_most = node->val;
                if (node->left) { q.push(node->left); ++tmp; }
                if (node->right) { q.push(node->right); ++tmp; }
            }
            v.push_back(right_most);
            tail = tmp;
        }
        return v;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    Solution sol;
    vector<int> v = sol.rightSideView(root);
    return 0;
}
