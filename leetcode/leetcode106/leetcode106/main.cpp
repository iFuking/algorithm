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
	TreeNode* build_tree(vector<int>& postorder, int post_left, int post_right, 
		vector<int>& inorder, int in_left, int in_right)
	{
		if (post_left>post_right || in_left>in_right) return NULL;
		int fp = in_left;
		while (inorder[fp++] != postorder[post_right]) ;
		int left_size = fp-1-in_left, right_size = in_right-fp+1;
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = postorder[post_right];
		root->left = build_tree(postorder, post_left, post_left+left_size-1, 
			inorder, in_left, in_left+left_size-1);
		root->right = build_tree(postorder, post_right-right_size, post_right-1, 
			inorder, fp, in_right);
		return root;
	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return build_tree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

