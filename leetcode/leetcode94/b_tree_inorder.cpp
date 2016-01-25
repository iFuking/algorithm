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
    void inorder_traversal(TreeNode* root, vector<int> &value) {
        if (!root) return;
        inorder_traversal(root->left, value);
        value.push_back(root->val);
        inorder_traversal(root->right, value);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorder_traversal(root, inorder);
        return inorder;
    }
};

int main()
{
    return 0;
}
