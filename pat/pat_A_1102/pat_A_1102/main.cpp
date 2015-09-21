#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int key;
	int left, right;
}Tree;
const int maxn = 11;
Tree tree[maxn];
int N;
bool visit[maxn];
vector<int> res;

void level_order(int r)
{
	vector<int> ans;
	queue<int> q;
	q.push(r);
	while (!q.empty())
	{
		int k = q.front(); q.pop();
		ans.push_back(k);
		if (tree[k].left != -1) q.push(tree[k].left);
		if (tree[k].right != -1) q.push(tree[k].right);
	}
	for (int i = 0; i < ans.size()-1; ++i) printf("%d ", ans[i]);
	printf("%d\n", ans[ans.size()-1]);
	return;
}

void convert_tree()
{
	for (int i = 0; i < N; ++i)
	{
		int tmp = tree[i].left;
		tree[i].left = tree[i].right;
		tree[i].right = tmp;
	}
	return;
}

void save_inorder(int r)
{
	if (tree[r].left != -1) save_inorder(tree[r].left);
	res.push_back(r);
	if (tree[r].right != -1) save_inorder(tree[r].right);
	return;
}

void in_order(int r)
{
	save_inorder(r);
	for (int i = 0; i < res.size()-1; ++i) printf("%d ", res[i]);
	printf("%d\n", res[res.size()-1]);
	return;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		getchar();
		char ch1, ch2; scanf("%c %c", &ch1, &ch2);
		int l, r;
		if (ch1 == '-') l = -1;
		else l = ch1 - '0';
		if (ch2 == '-') r = -1;
		else r = ch2 - '0';
		
		tree[i].key = i;
		tree[i].left = l; tree[i].right = r;
	}

	for (int i = 0; i < N; ++i) {
		if (tree[i].left != -1) visit[tree[i].left] = true;
		if (tree[i].right != -1) visit[tree[i].right] = true;
	}
	int root;
	for (int i = 0; i < N; ++i) {
		if (!visit[i]) { root = i; break; }
	}

	convert_tree();
	level_order(root);
	in_order(root);
	return;
}

int main()
{
	solve();
	return 0;
}