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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *h = new ListNode(10000007);
		h->next = head;
		n -= m;

		ListNode *pm = h;
		while (--m) pm = pm->next;
		ListNode *p = pm->next;
		while (n--) {
			ListNode *next = p->next;
			p->next = next->next;
			next->next = pm->next;
			pm->next = next;
		}
		return h->next;
    }
};

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.reverseBetween(l1, 2, 4);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}