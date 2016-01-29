#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<pair<int, int>, vector<TreeNode*>> dp;

    vector<TreeNode*> generate_trees(int s, int e) {
        if (dp[make_pair(s, e)].size() > 0) return dp[make_pair(s, e)];
        vector<TreeNode*> tree;
        if (s > e) { tree.push_back(NULL); return tree; }
        for (int index = s; index <= e; ++index) {
            vector<TreeNode*> left = generate_trees(s, index-1);
            vector<TreeNode*> right = generate_trees(index+1, e);
            dp[make_pair(s, index-1)] = left; dp[make_pair(index+1, e)] = right;
            for (int i = 0; i < left.size(); ++i) {
                for (int j = 0; j < right.size(); ++j) {
                    TreeNode *node = new TreeNode(index);
                    node->left = left[i]; node->right = right[j];
                    tree.push_back(node);
                }
            }
        }
        return tree;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generate_trees(1, n);
    }
};

int main()
{
    return 0;
}
