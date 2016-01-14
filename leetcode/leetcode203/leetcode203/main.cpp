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
    ListNode* removeElements(ListNode* head, int val) {
		ListNode *h = new ListNode(10000007); h->next = head;
		head = h;
		ListNode *pre = NULL;
		while (head) {
			if (head->val == val) {
				pre->next = head->next;
				head = pre->next;
				continue;
			}
			pre = head;
			head = head->next;
		}
		return h->next;
    }
};

int main()
{
	int a[] = {6, 1};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.removeElements(l1, 6);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}