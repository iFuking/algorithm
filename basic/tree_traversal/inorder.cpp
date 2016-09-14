#include <deque>
#include <stack>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {} 
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode *node = root;

        while (!st.empty() || node) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top(); st.pop();
                v.push_back(node->val);
                node = node->right;
            }
        }
        return v;
    }
};