#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef struct {
	string addr;
	int data;
	string next;
}NODE;
const int maxn = 1e5 + 10;
string st_addr;
int N, K;
NODE list[maxn];
map<string, NODE> nodes;

void init()
{
	cin >> st_addr >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		NODE node;
		cin >> node.addr >> node.data >> node.next;
		nodes[node.addr] = node;
	}
	return;
}

void swap(NODE *n1, NODE *n2)
{
	NODE n = *n1;
	*n1 = *n2;
	*n2 = n;
	return;
}

void solve()
{
	list[0] = nodes[st_addr];
	string addr = nodes[st_addr].next;
	for (int i = 1; addr != "-1"; addr = nodes[addr].next) {
		list[i++] = nodes[addr];
	}

	for (int i = 0; i < N-N%K; i += K) {
		for (int j = 0; j < K/2; ++j) {
			swap(&list[j+i], &list[K-1-j+i]);
		}
	}

	printf("%s %d ", list[0].addr.c_str(), list[0].data);
	for (int i = 1; i < N; ++i) {
		printf("%s\n%s %d ", list[i].addr.c_str(), list[i].addr.c_str(), list[i].data);
	}
	printf("-1\n");
	return;
}

int main(int argc, char *argv[])
{
	init();
	solve();
	return 0;
}