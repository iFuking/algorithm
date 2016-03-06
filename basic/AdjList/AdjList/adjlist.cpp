#include <iostream>
using namespace std;
typedef struct Node {
	int val;
	Node *next;
}Node;

int main()
{
	Node list[6];
	for (int i = 1; i <= 5; i++)
	{
		list[i].val = i;
		list[i].next = NULL;
	}

	int u, v;
	for (int e = 0; e < 7; e++)
	{
		cin >> u >> v;
		Node *p = (Node *)malloc(sizeof(Node));
		p->val = v;
		p->next = list[u].next;
		list[u].next = p;
	}
	return 0;
}