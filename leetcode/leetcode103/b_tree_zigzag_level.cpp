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
    void reverse_vec(vector<int> &vec) {
        for (int i = 0; i < vec.size()/2; ++i) swap(vec[i], vec[vec.size()-1-i]);
        return;
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > zigzag_level;
        if (!root) return zigzag_level;

        queue<TreeNode*> q; q.push(root);
        int head = 0, tail = 1, tmp = tail, step = 1;
        while (!q.empty()) {
            vector<int> level;
            while (head < tail) {
                TreeNode *tree = q.front(); q.pop(); ++head;
                level.push_back(tree->val);
                if (tree->left) { q.push(tree->left); ++tmp; }
                if (tree->right) { q.push(tree->right); ++tmp; }
            }
            if (step % 2 == 0) reverse_vec(level);
            zigzag_level.push_back(level);
            ++step; tail = tmp;
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    Solution sol;
    vector<vector<int> > zigzag_level = sol.zigzagLevelOrder(root);
    for (int i = 0; i < zigzag_level.size(); ++i) {
        for (int j = 0; j < zigzag_level[i].size(); ++j) {
            cout << zigzag_level[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
