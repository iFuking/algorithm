#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//	ListNode *rev;
//
//    bool isPalindrome(ListNode* head) {
//        rev = head;
//		return backtrace_check(head);
//    }
//
//	bool backtrace_check(ListNode *p) {
//		if (!p) return true;
//		bool check_res = backtrace_check(p->next) & (p->val == rev->val);
//		rev = rev->next;
//		return check_res;
//	}
//};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *p = head, *revp = NULL;
		while (p) {
			ListNode *node = new ListNode(p->val);
			node->next = revp;
			revp = node;
			p = p->next;
		}

		p = head;
		while (p) {
			if (p->val != revp->val) return false;
			p = p->next; revp = revp->next;
		}
		return true;
    }
};

int main()
{
	int a[] = {1, 2, 3, 3, 2, 1};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	Solution sol;
	cout << sol.isPalindrome(l1) << endl;
	//ListNode *p = sol.deleteNode(l1);
	//while (p) {
	//	cout << p->val << " ";
	//	p = p->next;
	//}
	//cout << endl;
	return 0;
}