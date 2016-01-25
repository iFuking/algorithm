#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sum;

    void dfs(TreeNode* root, vector<int> &num) {
        if (!root) return;
        num.push_back(root->val);
        if (!root->left && !root->right) {
            int s = 0;
            for (int i = 0; i < num.size(); ++i) s = 10*s+num[i];
            sum += s;
        }
        if (root->left) dfs(root->left, num);
        if (root->right) dfs(root->right, num);
        num.pop_back();
        return;
    }

    int sumNumbers(TreeNode* root) {
        sum = 0;
        vector<int> v; dfs(root, v);
        return sum;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    Solution sol;
    cout << sol.sumNumbers(root) << endl;
    return 0;
}
