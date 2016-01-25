#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int max_depth_tree(TreeNode* root) {
        if (!root) return 0;
        return max(max_depth_tree(root->left), max_depth_tree(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) &&
            abs(max_depth_tree(root->left)-max_depth_tree(root->right))<=1;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2); root->right->right = new TreeNode(3);
    Solution sol;
    cout << sol.isBalanced(root) << endl;
    return 0;
}
