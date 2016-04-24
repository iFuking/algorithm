#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int n): val(n), next(NULL) {}
};

class Solution {
public:
	ListNode *merge_two_list(ListNode *l1, ListNode *l2) {
		if (!l1) return l2;
		if (!l2) return l1;

		if (l1->val < l2->val) {
			l1->next = merge_two_list(l1->next, l2);
			return l1;
		}

		l2->next = merge_two_list(l1, l2->next);
		return l2;
	}

    ListNode* sortList(ListNode* head) {
    	if (!head || !head->next) return head;

        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
        	pre = slow;
        	slow = slow->next;
        	fast = fast->next->next;
        }

        pre->next = NULL;

       	ListNode *p = sortList(head);
       	ListNode *q = sortList(slow);

        return merge_two_list(p, q);
    }
};

int main() {
	return 0;
}