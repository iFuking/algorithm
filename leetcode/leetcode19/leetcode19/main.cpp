#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_size = 0;
		ListNode *p = head;
		while (p) {
			++list_size;
			p = p->next;
		}
		if (list_size == 1) return NULL;
		if (list_size == n) return head->next;

		ListNode *lst = NULL;
		int cnt = 0; p = head;
		while (p) {
			++cnt;
			ListNode *node = new ListNode(p->val);
			node->next = lst;
			lst = node;
			if (cnt == list_size-n) {
				p->next = p->next->next;
			}
			p = p->next;
		}

		ListNode *rev = NULL;
		while (lst) {
			ListNode *node = new ListNode(lst->val);
			node->next = rev;
			rev = node;
			lst = lst->next;
		}
		return rev;
    }
};

int main()
{
	int a[] = {1, 2};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.removeNthFromEnd(l1, 2);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}