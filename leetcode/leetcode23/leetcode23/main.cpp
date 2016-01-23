#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* merge_two_lists(ListNode* l1, ListNode* l2)
	{
		if (!l1) return l2;
		if (!l2) return l1;
		
		if (l1->val < l2->val) {
			l1->next = merge_two_lists(l1->next, l2);
			return l1;
		} else {
			l2->next = merge_two_lists(l1, l2->next);
			return l2;
		}
		return NULL;
	}

	ListNode* partition(vector<ListNode*>& lists, int left, int right)
	{
		if (left == right) return lists[left];

		int mid = (left+right) >> 1;
		ListNode *l1 = partition(lists, left, mid);
		ListNode *l2 = partition(lists, mid+1, right);
		return merge_two_lists(l1, l2);
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
		return partition(lists, 0, lists.size()-1);
    }
};

int main()
{
	int a[] = {1, 3, 5};
	ListNode *l1 = NULL;
	for (int i = sizeof(a)/sizeof(a[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(a[i]);
		node->next = l1;
		l1 = node;
	}

	int b[] = {2, 4, 6};
	ListNode *l2 = NULL;
	for (int i = sizeof(b)/sizeof(b[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(b[i]);
		node->next = l2;
		l2 = node;
	}

	int c[] = {1, 2, 3, 4, 5};
	ListNode *l3 = NULL;
	for (int i = sizeof(c)/sizeof(c[0])-1; i >= 0; --i) {
		ListNode *node = new ListNode(c[i]);
		node->next = l3;
		l3 = node;
	}

	vector<ListNode*> v;
	v.push_back(l1); v.push_back(l2); v.push_back(l3);

	Solution sol;
	ListNode *p = sol.mergeKLists(v);
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}