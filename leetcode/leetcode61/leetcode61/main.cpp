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
    ListNode* rotateRight(ListNode* head, int k) {
		ListNode *p = head; int list_size = 0;
		while (p) {
			++list_size;
			p = p->next;
		}
		if (list_size < 1) return head;
		k = k % list_size;
		if (k == 0) return head;

		ListNode *h = head; p = head;
		for (int i = 1; i<=list_size && p; ++i) {
			if (i == list_size-k) {
				head = p->next;
				p->next = NULL;
				p = head;
				continue;
			}
			if (i == list_size) {
				p->next = h;
				break;
			}
			p = p->next;
		}
		return head;
    }
};

int main()
{
	int a[] = {1};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.rotateRight(l1, 0);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}