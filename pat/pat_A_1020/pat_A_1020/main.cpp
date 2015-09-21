#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

typedef struct Tree{
	int data;
	Tree *left;
	Tree *right;
}Tree;
const int maxn = 31;
int N;
int post_order[maxn], in_order[maxn];
vector<int> level_order;

Tree *build_tree(int post_left, int post_right, int in_left, int in_right)
{
	if (post_left>post_right || in_left>in_right) return NULL;
	int p = in_left;
	while (in_order[p++] != post_order[post_right]) ;
	int left_size = p-1-in_left, right_size = in_right-p+1;
	Tree *root = (Tree *)malloc(sizeof(Tree));
	root->data = post_order[post_right];
	root->left = build_tree(post_left, post_left+left_size-1, in_left, in_left+left_size-1);
	root->right = build_tree(post_right-right_size, post_right-1, in_right-right_size+1, in_right);
	return root;
}

void save_level_order(Tree *tree)
{
	queue<Tree*> q;
	q.push(tree);
	while (!q.empty())
	{
		Tree *t = q.front(); 
		level_order.push_back(t->data); 
		q.pop();
		if (t->left != NULL) q.push(t->left); 
		if (t->right != NULL) q.push(t->right);
	}
	return;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i) scanf("%d", &post_order[i]);
	for (int i = 0; i < N; ++i) scanf("%d", &in_order[i]);
	Tree *root = build_tree(0, N-1, 0, N-1);
	save_level_order(root);
	for (int i = 0; i < level_order.size()-1; ++i) printf("%d ", level_order[i]);
	printf("%d\n", level_order[level_order.size()-1]);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}