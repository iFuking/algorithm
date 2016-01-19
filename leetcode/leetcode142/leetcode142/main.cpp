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
    ListNode *detectCycle(ListNode *head) {
		if (!head) return NULL;
		ListNode *slow = head, *fast = head;
		while (slow && fast) {
			slow = slow->next;
			if (fast->next) fast = fast->next->next;
			else fast = NULL;
			if (slow == fast) break;
		}
		if (!slow || !fast) return NULL;

		fast = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
    }
};

int main()
{
	ListNode *l1 = NULL, *l2 = NULL;
	l1 = new ListNode(1); l2 = new ListNode(2);
	l1->next = l2; l2->next = l1;

	Solution sol;
	ListNode *p = sol.detectCycle(l1);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}