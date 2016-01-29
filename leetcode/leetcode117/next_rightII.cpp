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
    void connect(TreeLinkNode *root) {
        if (!root) return;

        connect(root->left);
        connect(root->right);
        return;
    }
};

int main()
{
    return 0;
}
