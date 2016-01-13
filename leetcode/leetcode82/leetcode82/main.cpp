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
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode *h = new ListNode(10000007); h->next = head;
		ListNode *pre = NULL, *p = h;
		while (p && p->next) {
			ListNode *pn = p->next; bool found = false;
			while (p && pn && p->val==pn->val) {
				found = true;
				p = p->next; pn = pn->next;
			}
			if (found) pre->next = p->next;
			else pre = p;
			p = p->next;
		}
		return h->next;
    }
};

int main()
{
	int a[] = {1, 1};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.deleteDuplicates(l1);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}