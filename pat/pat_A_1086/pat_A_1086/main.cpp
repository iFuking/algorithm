#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef struct Tree {
	int key;
	Tree *left;
	Tree *right;
};
const int max_op = 5;
int N, iter = 0;
vector<int> post_keys;

Tree *build_tree()
{
	Tree *root = NULL;
	if (iter < 2*N) {
		char op[max_op]; scanf("%s", op);
		if (strcmp(op, "Push") == 0) {
			int input; scanf("%d", &input);
			root = (Tree *)malloc(sizeof(Tree));
			root->key = input;
			++iter;
		} else if (strcmp(op, "Pop") == 0) { ++iter; return NULL; }
		root->left = build_tree();
		root->right = build_tree();
	}
	return root;
}

void save_postorder(Tree *t)
{
	if (t->left != NULL) save_postorder(t->left);
	if (t->right != NULL) save_postorder(t->right);
	post_keys.push_back(t->key);
	return;
}

void solve()
{
	cin >> N;
	Tree *root = build_tree();
	save_postorder(root);
	for (int i = 0; i < post_keys.size()-1; ++i) printf("%d ", post_keys[i]);
	printf("%d\n", post_keys[N-1]);
	return;
}

int main()
{
	solve();
	return 0;
}