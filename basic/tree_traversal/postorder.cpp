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
    vector<int> postorderTraversal(TreeNode* root) {
        deque<int> d;
        stack<TreeNode*> st;
        TreeNode *node = root;

        while (!st.empty() || node) {
            if (node) {
                st.push(node);
                d.push_front(node->val);
                node = node->right;
            } else {
                node = st.top(); st.pop();
                node = node->left;
            }
        }
        return vector<int>(d.begin(), d.end());
    }
};