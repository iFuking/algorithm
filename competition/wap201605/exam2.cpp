#include <iostream>
#include <cstdio>
using namespace std;

typedef struct TrieNode {
    long long val;
    TrieNode *left;
    TrieNode *right;
    TrieNode(): val(0LL), left(NULL), right(NULL) {}
}TrieNode;

const int BITSIZE = 41;

void insert_trie(TrieNode *root, long long val) {
    TrieNode *p = root;
    for (int b = BITSIZE-1; b >= 0; --b) {
        if (((val>>b) & 1) == 0) {
            if (p->left == NULL) {
                p->left = new TrieNode();
            }
            p = p->left;
        } else {
            if (p->right == NULL) {
                p->right = new TrieNode();
            }
            p = p->right;
        }

        if (b == 0) {
            p->val = val;
        }
    }
    return;
}

long long pruffix_xor(TrieNode *root, long long val) {
    long long ans = 0;
    TrieNode *p = root;
    for (int b = BITSIZE-1; b >= 0; --b) {
        if (((val>>b) & 1) == 0) {
            if (p->right) p = p->right;
            else p = p->left;
        } else {
            if (p->left) p = p->left;
            else p = p->right;
        }

        if (b == 0) {
            ans = val^p->val;
        }
    }
    return ans;
}

void free_mem(TrieNode *root) {
    if (!root) return;
    if (root->left) free_mem(root->left);
    if (root->right) free_mem(root->right);
    delete root;
    return;
}

const int maxn = 1e5 + 10;
long long a[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    TrieNode *root = new TrieNode();
    insert_trie(root, 0);
    long long ans = 0, cur_xor = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        cur_xor ^= a[i];
        insert_trie(root, cur_xor);
    }

    cur_xor = 0;
    for (int i = n-1; i >= 0; --i) {
        cur_xor ^= a[i];
        ans = max(ans, pruffix_xor(root, cur_xor));
    }
    printf("%lld\n", ans);
    free_mem(root);
    return;
}

int main() {
    solve();
    return 0;
}