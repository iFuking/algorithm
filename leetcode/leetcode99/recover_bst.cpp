#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {} 
};

class Solution {
public:
    vector<pair<TreeNode*, TreeNode*> > mistake_pair(TreeNode *root) {
        vector<pair<TreeNode*, TreeNode*> > v;
        stack<TreeNode*> st;
        TreeNode *node = root, *pre = NULL;

        while (!st.empty() || node) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top(); st.pop();
                if (pre && pre->val>node->val) {
                    v.push_back(make_pair(pre, node));
                }
                pre = node;
                node = node->right;
            }
        }
        return v;
    }

    void recoverTree(TreeNode* root) {
        vector<pair<TreeNode*, TreeNode*> > v = mistake_pair(root);

        if (v.size() == 1) {
            int tmp = v[0].first->val;
            v[0].first->val = v[0].second->val;
            v[0].second->val = tmp;
            return;
        }
        int tmp = v[0].first->val;
        v[0].first->val = v[1].second->val;
        v[1].second->val = tmp;
        return;
    }
};

void level_order(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front(); q.pop();
        if (node) {
            cout << node->val << ",";
        } else {
            cout << "null,";
        }
        if (node) {
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << endl;
    return;
}

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    level_order(root);
    sol.recoverTree(root);
    level_order(root);
    return 0;
}