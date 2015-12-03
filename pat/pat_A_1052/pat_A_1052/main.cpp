#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

const int maxd = 6;
typedef struct {
	char addr[maxd];
	int key;
	char next[maxd];
}NODE;

map<string, NODE> node;
vector<NODE> list;

bool cmp(const NODE &n1, const NODE &n2) { return n1.key < n2.key; }

void solve()
{
	int N; char start_addr[maxd]; scanf("%d %s", &N, start_addr);
	for (int i = 0; i < N; ++i) {
		NODE n; scanf("%s %d %s", n.addr, &n.key, n.next);
		node[n.addr] = n;
	}
	if (node.find(start_addr) == node.end()) {
		printf("0 -1\n"); return;
	}

	string addr = start_addr;
	for ( ; addr != "-1"; addr = node[addr].next) list.push_back(node[addr]);
	sort(list.begin(), list.end(), cmp);

	printf("%d %s\n", list.size(), list[0].addr);
	printf("%s %d ", list[0].addr, list[0].key);
	for (int i = 1; i < list.size(); ++i) {
		printf("%s\n%s %d ", list[i].addr, list[i].addr, list[i].key);
	}
	printf("-1\n");
	return;
}

int main()
{
	solve();
	return 0;
}