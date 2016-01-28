#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// idea of inorder traverse binary tree using iteration, but not recursion
class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode *root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = st.top(); st.pop();
        int value = node->val;
        node = node->right;
        while (node) {
            st.push(node);
            node = node->left;
        }
        return value;
    }
};

int main()
{
    return 0;
}
