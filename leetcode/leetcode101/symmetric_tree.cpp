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
//    TreeNode *build_tree(TreeNode *root)
//    {
//        if (!root) return NULL;
//        TreeNode *tree = new TreeNode(root->val);
//        tree->left = build_tree(root->right);
//        tree->right = build_tree(root->left);
//        return tree;
//    }
//
//    bool is_same_tree(TreeNode *p, TreeNode *q)
//    {
//        if (!p && !q) return true;
//        return p && q && p->val==q->val &&
//            is_same_tree(p->left, q->left) && is_same_tree(p->right, q->right);
//    }
//
//    bool isSymmetric(TreeNode* root) {
//        TreeNode *mirror = build_tree(root);
//        return is_same_tree(root, mirror);
//    }
//};

class Solution {
public:
    bool is_symmetric_tree(TreeNode *left, TreeNode *right)
    {
        if (!left && !right) return true;
        else if (left && !right) return false;
        else if (!left && right) return false;
        return left->val==right->val && is_symmetric_tree(left->left, right->right) &&
            is_symmetric_tree(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return is_symmetric_tree(root->left, root->right);
    }
};

int main()
{
    return 0;
}
