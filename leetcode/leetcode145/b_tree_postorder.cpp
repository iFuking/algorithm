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
    void find_postorder(TreeNode* root, vector<int> &postorder) {
        if (!root) return;
        find_postorder(root->left, postorder);
        find_postorder(root->right, postorder);
        postorder.push_back(root->val);
        return;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder; find_postorder(root, postorder);
        return postorder;
    }
};

int main()
{
    return 0;
}
