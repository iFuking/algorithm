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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *h = new ListNode(10000007);
		h->next = head;
		if (!head) return NULL;

		ListNode *p = head->next, *pre = head, *next = NULL;
		if (!p) return head;
		for ( ; p; p = next) {
			next = p->next;
			ListNode *it = h->next, *it_pre = h;
			for ( ; it != p; it = it->next) {
				if (p->val < it->val) {
					pre->next = next;
					p->next = it;
					it_pre->next = p;
					break;
				}
				it_pre = it;
			}
			if (it == p) pre = p;
		}
		return h->next;
    }
};

int main()
{
	int a[] = {4,19,14,5,-3,1,8,5,11,15};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.insertionSortList(l1);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}