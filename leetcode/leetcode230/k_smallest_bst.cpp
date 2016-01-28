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
//    int tree_nodes;
//
//    int cnt_tree_nodes(TreeNode* root) {
//        if (!root) return 0;
//        return cnt_tree_nodes(root->left)+1+cnt_tree_nodes(root->right);
//    }
//
//    int find_kth_smallest(TreeNode* root, int k) {
//        if (!root) return 0;
//        int left_subtree_nodes = cnt_tree_nodes(root->left);
//        if (left_subtree_nodes+1 == k) return root->val;
//        else if (left_subtree_nodes+1 > k) return kthSmallest(root->left, k);
//        return kthSmallest(root->right, k-left_subtree_nodes-1);
//    }
//
//    int kthSmallest(TreeNode* root, int k) {
//        tree_nodes = cnt_tree_nodes(root);
//        return find_kth_smallest(root, k);
//    }
//};

class Solution {
public:
    bool found;
    int cnt, ans;

    void inorder_traverse(TreeNode* root, int k) {
        if (found || !root) return;
        inorder_traverse(root->left, k);
        ++cnt;
        if (cnt == k) { ans = root->val; found = true; return; }
        inorder_traverse(root->right, k);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        found =  false; cnt = 0;
        inorder_traverse(root, k);
        return ans;
    }
};

int main()
{
    return 0;
}
