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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left || !root->right) return max(minDepth(root->left), minDepth(root->right))+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};

int main()
{
    return 0;
}
