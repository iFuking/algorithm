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
    bool hasCycle(ListNode *head) {
		if (!head) return false;
		ListNode *slow = head, *fast = head->next;
		while (slow && fast && slow!=fast) {
			slow = slow->next;
			if (fast->next)
				fast = fast->next->next;
			else fast = NULL;
		}
		if (!slow || !fast) return false;
		return true;
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
	cout << sol.hasCycle(l1) << endl;
	return 0;
}
