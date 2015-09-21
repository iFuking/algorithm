/*
DBACEGF ABCDEFG
BCAD CBAD
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct TreeNode {
	char data;
	TreeNode *left;
	TreeNode *right;
}TreeNode;
string pre_order, in_order;

TreeNode *build(int pre_left, int pre_right, int in_left, int in_right)
{
	if (pre_left>pre_right || in_left>in_right) return NULL;
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	int p = in_left;
	while (in_order[p++] != pre_order[pre_left]) ;
	int left_tree_size = p-1-in_left, right_tree_size = in_right-p+1;
	root->data = pre_order[pre_left];
	root->left = build(pre_left+1, pre_left+left_tree_size, in_left, in_left+left_tree_size-1);
	root->right = build(pre_left+left_tree_size+1, pre_right, p, in_right);
	return root;
}

void print_postorder(TreeNode *root)
{
	if (root == NULL) return;
	print_postorder(root->left);
	print_postorder(root->right);
	cout << root->data;
	return;
}

int main()
{
	cin >> pre_order >> in_order;
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	root = build(0, pre_order.length()-1, 0, in_order.length()-1);
	print_postorder(root);
	cout << endl;
	return 0;
}
