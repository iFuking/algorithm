#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    void invert_tree(TreeNode *root) {
//        if (!root) return;
//        TreeNode *tree_node = root->left; root->left = root->right; root->right = tree_node;
//        invert_tree(root->left);
//        invert_tree(root->right);
//        return;
//    }
//
//    TreeNode* invertTree(TreeNode* root) {
//        invert_tree(root);
//        return root;
//    }
//};

//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        if (!root) return NULL;
//        TreeNode *left = root->left, *right = root->right;
//        root->left = invertTree(right);
//        root->right = invertTree(left);
//        return root;
//    }
//};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode *tree_node = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tree_node);
        return root;
    }
};

void print_inorder(TreeNode *root) {
    if (!root) return;
    print_inorder(root->left);
    cout << root->val << " ";
    print_inorder(root->right);
    return;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    TreeNode *n1 = new TreeNode(2), *n2 = new TreeNode(7);
    n1->left = new TreeNode(1); n1->right = new TreeNode(3);
    n2->left = new TreeNode(6); n2->right = new TreeNode(9);
    root->left = n1; root->right = n2;
    print_inorder(root);
    cout << endl;
    Solution sol;
    root = sol.invertTree(root);
    print_inorder(root);
    return 0;
}
