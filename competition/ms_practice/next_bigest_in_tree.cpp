#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct node {
	int n;
	struct node *left;
	struct node *right;
}Node;

void inorder_search(Node *tree, vector<int> &v) {
	if (!tree) return;
	if (!tree->left) inorder_search(tree->left, v);
	v.push_back(tree->n);
	if (!tree->right) inorder_search(tree->right, v);
	return;
}

int b_search(int n, vector<int> &v) {
	int left = 0, right = v.size()-1;
	while (left <= right) {
		int mid = (left+right) >> 1;
		if (v[mid] < n) left = mid+1;
		else if (v[mid] > n) right = mid-1;
		else return mid;
	}
	return -1;
}

int next_value(Node *tree, int val) {
	vector<int> v;
	inorder_search(tree, v);
	int index = b_search(val, v);
	return v[index+1];
}

int main() {
	return 0;
}