#include <iostream>
#include <cstdlib>
using namespace std;
const int maxn = 1010;
int in_order[maxn], post_order[maxn], n;
int min_dis = 0x7fffffff;

typedef struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
}TreeNode;

// in_order left & right, post_order left & right
TreeNode *build_tree(int il, int ir, int pl, int pr)
{
	if (il > ir) return NULL;
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	root->data = post_order[pr];
	int index = il;
	while (in_order[index] != root->data) index++;
	int cnt = index-il;
	root->left = build_tree(il, index-1, pl, pl+cnt-1);
	root->right = build_tree(index+1, ir, pl+cnt, pr-1);
	return root;
}

// find distance between leaves and root
void dfs(TreeNode *tree, int ans)
{
	if (tree->left==NULL && tree->right==NULL)
	{
		ans += tree->data;
		if (ans < min_dis) min_dis = ans;
		return;
	}
	if (tree->left != NULL) dfs(tree->left, ans+tree->data);
	if (tree->right != NULL) dfs(tree->right, ans+tree->data);
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> in_order[i];
	for (int i = 0; i < n; i++) cin >> post_order[i];
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	root = build_tree(0, n-1, 0, n-1);
	dfs(root, 0);
	cout << min_dis << endl;
	return 0;
}