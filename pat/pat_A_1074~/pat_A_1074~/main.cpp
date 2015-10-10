#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct {
	string addr;
	int value;
}Node;
string start_addr;
int N, K;
map<string, string> rel;
map<string, int> node;
vector<Node> linked_list;

void swap(Node *n1, Node *n2)
{
	Node n = *n1;
	*n1 = *n2;
	*n2 = n;
	return;
}

void solve()
{
	cin >> start_addr >> N >> K;
	char addr[10], next_addr[10]; int value;
	for (int i = 0; i < N; ++i) 
	{
		scanf("%s %d %s", addr, &value, next_addr);
		rel[addr] = next_addr;
		node[addr] = value;
	}

	for (string addr =  start_addr; addr != "-1"; addr = rel[addr])
	{
		Node n;
		n.addr = addr; n.value = node[addr];
		linked_list.push_back(n);
	}

	if (linked_list.size() != N) N = linked_list.size();
	for (int i = 0; i < N-N%K; i += K) {
		for (int j = 0; j < K/2; ++j) 
			swap(&linked_list[i+j], &linked_list[i+K-1-j]);
	}

	printf("%s %d ", linked_list[0].addr.c_str(), linked_list[0].value);
	for (int i = 1; i < linked_list.size(); ++i) {
		printf("%s\n%s %d ", linked_list[i].addr.c_str(), linked_list[i].addr.c_str(), linked_list[i].value);
	}
	printf("-1\n");
	return;
}

int main()
{
	solve();
	return 0;
}


/*
1 9 4
1 1 2
2 2 3
3 3 4
4 4 5
5 5 6
6 6 7
7 7 8
8 8 9
9 9 -1
*/

/*
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 -1
*/