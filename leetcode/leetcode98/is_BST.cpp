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
    bool dfs(TreeNode* root, long long range_low, long long range_high)
    {
        if (!root) return true;
        return root->val>range_low && root->val<range_high &&
            dfs(root->left, range_low, root->val) && dfs(root->right, root->val, range_high);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};

int main()
{
    return 0;
}
