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
    int max_sum;

    int max_path_sum(TreeNode* root) {
        if (!root) return 0;
        // ignore those negtive subtree sum
        int left_sum = max(0, max_path_sum(root->left));
        int right_sum = max(0, max_path_sum(root->right));
        // find path(max_sum) in subtree
        max_sum = max(max_sum, left_sum+root->val+right_sum);
        // return for father nodes, only one path, left or right
        // choose from left_sum and right_sum
        return root->val+max(left_sum, right_sum);
    }

    int maxPathSum(TreeNode* root) {
        max_sum = 0x80000000;
        return max(max_sum, max_path_sum(root));
    }
};

int main()
{
    TreeNode *root = new TreeNode(-2);
    root->left = new TreeNode(1);
    Solution sol;
    cout << sol.maxPathSum(root) << endl;
    return 0;
}
