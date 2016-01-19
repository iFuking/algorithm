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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = NULL, *even = NULL;
		for (int i = 1; head; ++i) {
			ListNode *node = new ListNode(head->val);
			if (i % 2) {
				node->next = odd;
				odd = node;
			} else {
				node->next = even;
				even = node;
			}
			head = head->next;
		}

		ListNode *rev_odd = NULL, *rev_even = NULL;
		while (odd) {
			ListNode *node = new ListNode(odd->val);
			node->next = rev_odd;
			rev_odd = node;
			odd = odd->next;
		}
		while (even) {
			ListNode *node = new ListNode(even->val);
			node->next = rev_even;
			rev_even = node;
			even = even->next;
		}

		if (!rev_odd) return rev_even;
		if (!rev_even) return rev_odd;
		ListNode *p = rev_odd;
		while (p->next) p = p->next;
		p->next = rev_even;
		return rev_odd;
    }
};

int main()
{
	int a[] = {2, 1, 4, 3, 6, 5, 7, 8};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.oddEvenList(l1);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}