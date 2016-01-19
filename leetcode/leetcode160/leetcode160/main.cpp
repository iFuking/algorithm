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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pa = headA, *pb = headB;
		while (pa != pb) {
			pa = (pa==NULL ? headB : pa=pa->next);
			pb = (pb==NULL ? headA : pb=pb->next);
		}
		return pa;
    }
};

int main()
{
	int a[] = {5, 6, 7};
	ListNode *l = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l;
		l = node;
	}

	int b[] = {1, 3};
	ListNode *l1 = l;
	for (int i = sizeof(b)/sizeof(b[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(b[i]);
		node->next = l1;
		l1 = node;
	}
	int c[] = {0, 2, 4};
	ListNode *l2 = l;
	for (int i = sizeof(c)/sizeof(c[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(c[i]);
		node->next = l2;
		l2 = node;
	}

	Solution sol;
	ListNode *p = sol.getIntersectionNode(l1, l2);
	cout << p->val << endl;
	return 0;
}