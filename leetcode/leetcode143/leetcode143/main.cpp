#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return;

		ListNode *p = head; int list_len = 0;
		while (p) { ++list_len; p = p->next; }
		
		ListNode *pre_mid = NULL; p = head;
		for (int i = 1; i < list_len/2; ++i, p= p->next) ;
		pre_mid = p;

		ListNode *mid = pre_mid->next, *rev_half = NULL;
		while (mid) {
			ListNode *next = mid->next;
			mid->next = rev_half;
			rev_half = mid;
			mid = next;
		}
		pre_mid->next = rev_half;

		p = head;
		mid = pre_mid->next;
		pre_mid->next = NULL;
		while (mid) {
			ListNode *p_next = p->next;
			p->next = mid;
			p = mid;
			mid = p_next;
		}
		
		return;
    }
};

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	sol.reorderList(l1);
	return 0;
}