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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before = NULL, *after = NULL;
		while (head) {
			ListNode *node = new ListNode(head->val);
			if (head->val < x) {
				node->next = before;
				before = node;
			} else {
				node->next = after;
				after = node;
			}
			head = head->next;
		}

		ListNode *rev = NULL;
		while (after) {
			ListNode *node = new ListNode(after->val);
			node->next = rev;
			rev = node;
			after = after->next;
		}
		while (before) {
			ListNode *node = new ListNode(before->val);
			node->next = rev;
			rev = node;
			before = before->next;
		}
		
		return rev;
    }
};

int main()
{
	int a[] = {1, 4, 3, 2, 5, 2};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	ListNode *p = sol.partition(l1, 3);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}