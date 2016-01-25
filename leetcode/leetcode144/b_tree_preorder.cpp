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
    void find_preorder(TreeNode* root, vector<int> &preorder) {
        if (!root) return;
        preorder.push_back(root->val);
        find_preorder(root->left, preorder);
        find_preorder(root->right, preorder);
        return;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder; find_preorder(root, preorder);
        return preorder;
    }
};

int main()
{
    return 0;
}
