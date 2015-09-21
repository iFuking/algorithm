#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
};

const int maxchar = 10;
int N;
stack<int> st;
vector<int> order;
Tree *root;

Tree *build_tree(int l_left, int l_right, int r_left, int r_right)
{
	return root;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < 2*N; ++i)
	{
		char op[maxchar]; scanf("%s", op);
		if (strcmp(op, "Push") == 0) {
			int number; scanf("%d", &number);
			st.push(number);
		} else {
			order.push_back(st.top());
			st.pop();
		}
	}
	root = build_tree();
}

int main()
{
	solve();
	return 0;
}