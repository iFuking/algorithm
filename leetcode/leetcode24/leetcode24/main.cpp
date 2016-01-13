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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head;
		if (p && p->next) {
			p = head->next;
			head->next = swapPairs(p->next);
			p->next = head;
		}
		return p;
    }
};

int main()
{
	int a[] = {1, 2, 3, 4};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.swapPairs(l1);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}