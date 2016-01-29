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
    TreeNode *arr_to_bst(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = (left+right)>>1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = arr_to_bst(nums, left, mid-1);
        root->right = arr_to_bst(nums, mid+1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() < 1) return NULL;
        return arr_to_bst(nums, 0, nums.size()-1);
    }
};

int main()
{
    vector<int> v; v.push_back(0);
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(v);
    return 0;
}
