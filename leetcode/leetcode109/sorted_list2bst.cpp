#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* list_ij2bst(ListNode *head, ListNode *tail) {
        if (head == tail) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast!=tail && fast->next!=tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *tree = new TreeNode(slow->val);
        tree->left = list_ij2bst(head, slow);
        tree->right = list_ij2bst(slow->next, tail);
        return tree;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return list_ij2bst(head, NULL);
    }
};

int main() {
    return 0;
}
