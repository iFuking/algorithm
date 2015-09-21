#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

typedef struct {
	string addr, next;
	int key;
}Node;
const int maxn = 1e5 + 10;
const int addr_len = 6;
const int max_value = 1e4 + 10;
string start_addr;
int N;
vector<Node> list, abs_list;
map<string, int> addr_key;
map<string, string> addr_next;
vector<Node> kept, removed;
bool visit[max_value];

void solve()
{
	cin >> start_addr >> N;
	for (int i = 0; i < N; ++i) {
		char addr[addr_len], next[addr_len]; int key;
		scanf("%s %d %s", addr, &key, next);
		addr_key[addr] = key;
		addr_next[addr] = next;
	}
	for (string addr = start_addr; addr != "-1"; addr = addr_next[addr]) {
		Node node;
		node.addr = addr; node.key = addr_key[addr]; node.next = addr_next[addr]; 
		list.push_back(node);
	}

	for (int i = 0; i < list.size(); ++i) {
		abs_list.push_back(list[i]);
		abs_list[i].key = abs(abs_list[i].key);
	}
	for (int i = 0; i < list.size(); ++i) {
		if (!visit[abs_list[i].key]) {
			visit[abs_list[i].key] = true;
			kept.push_back(list[i]);
		} else removed.push_back(list[i]);
	}
	
	printf("%s %d ", kept[0].addr.c_str(), kept[0].key);
	for (int i = 1; i < kept.size(); ++i) printf("%s\n%s %d ", kept[i].addr.c_str(), kept[i].addr.c_str(), kept[i].key);
	printf("-1\n");
	if (removed.size() == 0) return;
	printf("%s %d ", removed[0].addr.c_str(), removed[0].key);
	for (int i = 1; i < removed.size(); ++i) printf("%s\n%s %d ", removed[i].addr.c_str(), removed[i].addr.c_str(), removed[i].key);
	printf("-1\n");
	return;
}

int main()
{
	solve();
	return 0;
}