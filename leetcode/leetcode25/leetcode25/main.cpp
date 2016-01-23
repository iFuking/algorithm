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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head; int cnt = 0;
		while (p && cnt<k) {
			p = p->next;
			++cnt;
		}
		if (cnt == k) {
			p = reverseKGroup(p, k);
			while (cnt--) {
				ListNode *next = head->next;
				head->next = p;
				p = head;
				head = next;
			}
			head = p;
		}
		return head;
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
	ListNode *p = sol.reverseKGroup(l1, 3);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}