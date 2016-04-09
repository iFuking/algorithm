#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct RULE {
    bool access;
    unsigned int ip;
    int mask;
};

struct TreeNode {
    bool val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(true), left(NULL), right(NULL) {}
};

const int maxn = 1e5 + 10;
const int maxs = 1e2 + 10;
int N, M;
RULE rules[maxn];

void getAddress(string address, unsigned int &ip, int &mask) {
    mask = -1; ip = 0;
    int head = 0;
    for (int i = 0; i < address.length(); i++) {
        if (address[i] == '.' || address[i] == '/') {
            ip <<= 8;
            ip += atoi(address.substr(head, i).c_str());
            head = i + 1;
        }
        if (i == address.length() - 1) {
            ip <<= 8;
            ip += atoi(address.substr(head, i + 1).c_str());
        }
        if (address[i] == '/') {
            mask = atoi(address.substr(i + 1, address.length()).c_str());
            address = address.substr(0, i);
        }
    }
    
}

TreeNode *addRule() {
    TreeNode *root = new TreeNode();
    for (int i = N-1; i >= 0; --i) {
        TreeNode *node = root;

        if (rules[i].mask == -1) {
            rules[i].mask = 32;
        }

        for (int j = 31; j >= 32-rules[i].mask; --j) {
            if (rules[i].ip & (1U<<j)) {
                if (node->right == NULL) {
                    node->right = new TreeNode();
                    node->right->val = node->val;
                }
                node = node->right;
            } else {
                if (node->left == NULL) {
                    node->left = new TreeNode();
                    node->left->val = node->val;
                }
                node = node->left;
            }
        }

        node->left = NULL; node->right = NULL;
        node->val = rules[i].access;
    }
    return root;
}

void check2(bool &response, unsigned int ip, TreeNode *root) {
    TreeNode *node = root;

    for (int i = 31; i >= 0; --i) {
        if (ip & (1U<<i)) {
            if (node->right == NULL) {
                response = node->val;
                return;
            }
            node = node->right;
        } else {
            if (node->left == NULL) {
                response = node->val;
                return;
            }
            node = node->left;
        }
    }

    response = node->val;
    return;
}

void check1(bool &response, unsigned int ip) {
    for (int j = 0; j < N; j++) {
        if (rules[j].mask == -1 && rules[j].ip != ip) {
            continue;
        }
        if ((rules[j].ip >> (32 - rules[j].mask)) == (ip >> (32 - rules[j].mask))) {
            response = rules[j].access;
            break;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        char access[maxs], address[maxs];
        scanf("%s %s", access, address);

        RULE r;
        if (access[strlen(access) - 1] == 'w') {
            r.access = true;
        } else {
            r.access = false;
        }

        getAddress(address, r.ip, r.mask);
        rules[i] = r;
    }

    TreeNode *root = addRule();

    for (int i = 0; i < M; i++) {
        char address[maxs];
        unsigned int ip;
        int nothing;

        scanf("%s", address);
        getAddress(address, ip, nothing);

        bool response = true;
        // check1(response, ip);
        check2(response, ip, root);

        if (response) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
