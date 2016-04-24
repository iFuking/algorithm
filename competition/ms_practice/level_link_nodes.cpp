#include <iostream>
#include <cstdio>
#include <stack>
#include <map>
#include <queue>
using namespace std;

typedef struct node {
	int n;
	struct node *left;
	struct node *right;
	struct node *level;
}Node;

void link_same_level(Node *tree) {
	queue<Node*> q; q.push(tree);

	int head = 0, tail = 1, tmp = tail;
	while (!q.empty()) {
		bool level_first = false;
		Node *level_pre = NULL;
		
		while (head < tail) {
			Node *node = q.front(); q.pop(); ++head;
			
			if (!level_first) level_first = true;
			else level_pre->level = node;
			level_pre = node;

			if (node->left) {
				q.push(node->left);
				++tmp;
			}
			if (node->right) {
				q.push(node->right);
				++tmp;
			}
		}

		level_pre->level = NULL;
		tail = tmp;
	}
	return;
}

void solve() {
	return;
}

int main() {
	solve();
	return 0;
}