#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef struct TrieNode {
	int val;
	TrieNode *left;
	TrieNode *right;
	TrieNode(): val(0), left(NULL), right(NULL) {}
}TrieNode;

const int BITSIZE = 32;

TrieNode *build_trie(vector<int> &v) {
	TrieNode *root = new TrieNode();
	for (int i = 0; i < v.size(); ++i) {
		TrieNode *p = root;
		for (int b = BITSIZE-1; b >= 0; --b) {
			if ((v[i] & (1<<b)) == 0) {
				if (p->left == NULL) {
					p->left = new TrieNode();
				}
				p = p->left;
			} else {
				if (p->right==NULL) {
					p->right = new TrieNode();
				}
				p = p->right;
			}

			if (b == 0) p->val = v[i];
		}
	}
	return root;
}

int max_xor(vector<int> &v, TrieNode *root) {
	int ans = 0;
	for (int i = 0; i < v.size(); ++i) {
		TrieNode *p = root;
		for (int b = BITSIZE-1; b >= 0; --b) {
			if ((v[i] & (1<<b)) == 0) {
				if (p->right) p = p->right;
				else p = p->left;
			} else {
				if (p->left) p = p->left;
				else p = p->right;
			}

			if (b == 0) {
				ans = max(ans, v[i]^p->val);
			}
		}
	}
	return ans;
}

void solve() {
	int n;
	while (scanf("%d", &n)) {
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			int a; scanf("%d", &a);
			v.push_back(a);
		}
		
		TrieNode *root = build_trie(v);
		cout << max_xor(v, root) << endl;
	}
	return;
}

int main() {
	solve();
	return 0;
}