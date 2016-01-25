#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void reverse_vec(vector<vector<int>> &vec) {
        for (int i = 0; i < vec.size()/2; ++i) swap(vec[i], vec[vec.size()-1-i]);
        return;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> level_order;
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
        reverse_vec(level_order);
        return level_order;
    }
};

int main()
{
    return 0;
}
