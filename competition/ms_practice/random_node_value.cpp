#include <iostream>
#include <cstdio>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef struct node {
	int n;
	struct node *left;
	struct node *right;
}Node;

void node_cnt(Node *root, map<Node*, int> &cnt) {
	if (!root) return;
	if (root->left) node_cnt(root->left, cnt);
	if (root->right) node_cnt(root->right, cnt);
	cnt[root] = cnt[root->left]+cnt[root->right]+1;
	return;
}

int random_node(Node *root, map<Node*, int> &cnt) {
	if (!root->left && !root->right) return root->n;

	int tree_size = cnt[root], left_size = cnt[root->left];
	int value = rand() % tree_size;

	if (!root->left) {
		if (value == 0) return root->n;
		return random_node(root->right, cnt);
	} else if (!root->right) {
		if (value == tree_size-1) return root->n;
		return random_node(root->left, cnt);
	}

	if (value < left_size) return random_node(root->left, cnt);
	else if (value == left_size) return root->n;
	return random_node(root->right, cnt);

}

int random_node_value(Node *root) {
	srand((unsigned int)time(NULL));
	map<Node*, int> cnt;
	node_cnt(root, cnt);

	return random_node(root, cnt);
}

void solve() {
	return;
}

int main() {
	solve();
	return 0;
}