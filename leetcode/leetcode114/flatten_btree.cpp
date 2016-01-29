#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    vector<TreeNode*> v;
//
//    void preorder_traverse(TreeNode* root) {
//        if (!root) return;
//        v.push_back(root);
//        preorder_traverse(root->left);
//        preorder_traverse(root->right);
//        return;
//    }
//
//    void flatten(TreeNode* root) {
//        TreeNode *node = root; preorder_traverse(node);
//        for (int i = 1; i < v.size(); ++i) {
//            node->right = v[i];
//            node = node->right;
//        }
//        return;
//    }
//};

class Solution {
public:
    TreeNode* preorder_traverse(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* node = new TreeNode(root->val);
        node->left = NULL;
        node->right = preorder_traverse(root->left);
        node->right->right = preorder_traverse(root->right);
        return NULL;
    }

    void flatten(TreeNode* root) {
        root = preorder_traverse(root);
        return;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    root->left->left = new TreeNode(5); root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(9); root->right->right = new TreeNode(7);
    Solution sol; sol.flatten(root);
    return 0;
}
