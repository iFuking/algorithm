#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution {
public:
	TreeNode* build_tree(vector<int>& preorder, int pre_left, int pre_right, 
		vector<int>& inorder, int in_left, int in_right)
	{
		if (pre_left>pre_right || in_left>in_right) return NULL;
		int fp = in_left;
		while (fp<=in_right && inorder[fp++]!=preorder[pre_left]) ;
		int left_size = fp-1-in_left, right_size = in_right-fp+1;
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = preorder[pre_left];
		root->left = build_tree(preorder, pre_left+1, pre_left+left_size, 
			inorder, in_left, in_left+left_size-1);
		root->right = build_tree(preorder, pre_right-right_size+1, pre_right, 
			inorder, fp, in_right);
		return root;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build_tree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

int main()
{
	Solution sol;
	
	return 0;
}

