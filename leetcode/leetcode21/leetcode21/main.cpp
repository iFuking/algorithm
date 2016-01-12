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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = NULL;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				ListNode *node = new ListNode(l1->val);
				node->next = p;
				p = node;
				l1 = l1->next;
			} else {
				ListNode *node = new ListNode(l2->val);
				node->next = p;
				p = node;
				l2 = l2->next;
			}
		}

		while (l1) {
			ListNode *node = new ListNode(l1->val);
			node->next = p;
			p = node;
			l1 = l1->next;
		}
		while (l2) {
			ListNode *node = new ListNode(l2->val);
			node->next = p;
			p = node;
			l2 = l2->next;
		}

		ListNode *revp = NULL;
		while (p) {
			ListNode *node = new ListNode(p->val);
			node->next = revp;
			revp = node;
			p = p->next;
		}
		return revp;
    }
};

int main()
{
	int a[] = {2, 4, 5};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	int b[] = {4, 5, 6};
	ListNode *l2 = NULL;
	for (int i = sizeof(b)/sizeof(b[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(b[i]);
		node->next = l2;
		l2 = node;
	}

	Solution sol;
	ListNode *p = sol.mergeTwoLists(l1, l2);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}