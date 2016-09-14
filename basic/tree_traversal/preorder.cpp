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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode *node = root;
        
        while (!st.empty() || node) {
        	if (node) {
        		st.push(node);
        		v.push_back(node->val);
        		node = node->left;
        	} else {
        		node = st.top(); st.pop();
        		node = node->right;
        	}
        }
        return v;
    }
};