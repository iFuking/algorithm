#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct  {
	int left, right;
	int key;
}Node;
const int maxn = 110;
Node tree[maxn];
int keys[maxn], iter = 0;
queue<Node> q;
vector<int> level_order;

bool cmp(const int &k1, const int &k2) { return k1 < k2; }

void build_tree(int index)
{
	if (tree[index].left != -1) build_tree(tree[index].left);
	tree[index].key = keys[iter++];
	if (tree[index].right != -1) build_tree(tree[index].right);
	return;
}

void solve()
{
	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		Node node; scanf("%d %d", &node.left, &node.right);
		tree[i] = node;
	}
	for (int i = 0; i < N; ++i) scanf("%d", &keys[i]);
	
	sort(keys, keys+N, cmp);
	build_tree(0);
	q.push(tree[0]);
	while (!q.empty()) {
		Node node = q.front(); q.pop();
		level_order.push_back(node.key);
		if (node.left != -1) q.push(tree[node.left]);
		if (node.right != -1) q.push(tree[node.right]);
	}
	for (int i = 0; i < level_order.size()-1; ++i) printf("%d ", level_order[i]);
	printf("%d\n", level_order[level_order.size()-1]);
	return;
}

int main()
{
	solve();
	return 0;
}