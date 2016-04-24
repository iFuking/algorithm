#include <iostream>
#include <cstdio>
#include <stack>
#include <map>
using namespace std;

// typedef struct node {
// 	struct node *left;
// 	struct node *right;
// 	struct node *parent;
// }Node;

// Node *get_least_common_parent(Node *x, Node *y) {
// 	stack<Node*> stx, sty;
// 	stx.push(x); sty.push(y);

// 	while (x->parent) {
// 		stx.push(x->parent);
// 		x = x->parent;
// 	}
// 	while (y->parent) {
// 		sty.push(y->parent);
// 		y = y->parent;
// 	}

// 	Node *common = NULL;
// 	while (!stx.empty() && !sty.empty() && stx.top()==sty.top()) {
// 		common = stx.top();
// 		stx.pop(); sty.pop();
// 	}

// 	return common;
// }

typedef struct node {
	struct node *left;
	struct node *right;
}Node;

void find_path(Node *x, Node *tree, map<Node*, Node*> &path, bool &flag) {
	if (flag || !tree) return;
	if (tree == x) { flag = true; return; }
	if (tree->left) {
		path[tree->left] = tree;
		find_path(x, tree->left, path, flag);
	} else if (tree->right) {
		path[tree->right] = tree;
		find_path(x, tree->right, path, flag);
	}
	return;
}

Node *get_least_common_parent(Node *x, Node *y, Node *root) {
	map<Node*, Node*> pathx, pathy;
	bool flagx = false, flagy = false;
	find_path(x, root, pathx, flagx);
	find_path(y, root, pathy, flagy);

	stack<Node*> stx, sty;
	stx.push(x); sty.push(y);

	while (pathx[x] != NULL) {
		stx.push(pathx[x]);
		x = pathx[x];
	}
	while (pathy[y] != NULL) {
		sty.push(pathy[y]);
		y = pathy[y];
	}

	Node *common = NULL;
	while (!stx.empty() && !sty.empty() && stx.top()==sty.top()) {
		common = stx.top();
		stx.pop(); sty.pop();
	}

	return common;
}

void solve() {
	return;
}

int main() {
	solve();
	return 0;
}