#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//class Solution {
//public:
//    void connect(TreeLinkNode *root) {
//        if (!root) return;
//        queue<TreeLinkNode*> q; q.push(root);
//        int head = 0, tail = 1, tmp = tail;
//        while (!q.empty()) {
//            TreeLinkNode *last = NULL;
//            while (head < tail) {
//                TreeLinkNode *node = q.front(); q.pop(); ++head;
//                if (last) last->next = node;
//                if (node->left) { q.push(node->left); ++tmp; }
//                if (node->right) { q.push(node->right); ++tmp; }
//                last = node;
//            }
//            tail = tmp;
//        }
//        return;
//    }
//};

//class Solution {
//public:
//    void connect(TreeLinkNode *root) {
//        if (!root || !root->left) return;
//        root->left->next = root->right;
//        if (root->next) root->right->next = root->next->left;
//        connect(root->left);
//        connect(root->right);
//        return;
//    }
//};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *level_start = root, *p = NULL;
        while (level_start->left) {
            p = level_start;
            while (p) {
                p->left->next = p->right;
                if (p->next) p->right->next = p->next->left;
                p = p->next;
            }
            level_start = level_start->left;
        }
        return;
    }
};

int main()
{
    return 0;
}
