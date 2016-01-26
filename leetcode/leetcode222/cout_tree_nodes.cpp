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
    int get_tree_height(TreeNode* root) {
        if (!root) return 0;
        return get_tree_height(root->left)+1;
    }

    bool has_node(TreeNode* root, int n, int h) {
        if (!root) return false;
        else if (!h) return true;
        if (n & 1<<(h-1)) return has_node(root->right, n, h-1);
        return has_node(root->left, n, h-1);
    }

    int countNodes(TreeNode* root) {
        int height = get_tree_height(root);
        if (!height) return 0;
        int left = 0, right = (1<<height-1)-1;
        while (left <= right) {
            int mid = (left+right) >> 1;
            if (has_node(root, mid, height-1)) left = mid+1;
            else right = mid-1;
        }
        return left-1+(1<<height-1);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;
    cout << sol.countNodes(root) << endl;
    return 0;
}
