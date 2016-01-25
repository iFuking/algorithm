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
    vector<vector<int> > paths;

    void find_path_sum(TreeNode* root, int sum, vector<int> &path) {
        if (!root && sum==0) { paths.push_back(path); return; }
        if (!root) return;

        if (!root->left && !root->right) {
            path.push_back(root->val);
            find_path_sum(root->right, sum-root->val, path);
            path.pop_back();
            return;
        }

        if (root->left) {
            path.push_back(root->val);
            find_path_sum(root->left, sum-root->val, path);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->val);
            find_path_sum(root->right, sum-root->val, path);
            path.pop_back();
        }

        return;
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if (!root) return paths;
        vector<int> path; find_path_sum(root, sum, path);
        return paths;
    }
};

int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1); root->right = new TreeNode(1);
    Solution sol;
    vector<vector<int> > v = sol.pathSum(root, 1);
    return 0;
}
