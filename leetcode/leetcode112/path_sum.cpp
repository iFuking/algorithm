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
    bool has_path_sum(TreeNode* root, int sum) {
        if (!root && sum==0) return true;
        if (!root) return false;

        if (root->left && !root->right) {
            return has_path_sum(root->left, sum-root->val);
        } else if (!root->left && root->right) {
            return has_path_sum(root->right, sum-root->val);
        }
        return has_path_sum(root->left, sum-root->val) ||
            has_path_sum(root->right, sum-root->val);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return has_path_sum(root, sum);
    }
};

int main()
{
    int sum = 1;
    if (!sum) cout << "pos" << endl;
    else cout << "neg" << endl;
    return 0;
}
