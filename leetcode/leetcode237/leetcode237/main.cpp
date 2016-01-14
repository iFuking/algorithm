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
    void deleteNode(ListNode* node) {
		ListNode *node_next = node->next;
		node->val = node_next->val;
		node->next = node_next->next;
		free(node_next);
		return;
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
	sol.deleteNode(l1);
	//while (p) {
	//	cout << p->val << " ";
	//	p = p->next;
	//}
	//cout << endl;
	return 0;
}