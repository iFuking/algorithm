#include <iostream>
#include <map>
using namespace std;

const int maxn = 1e5 + 10;
int hash_map[maxn], visit[maxn];

void solve()
{
	int s1, s2, N; cin >> s1 >> s2 >> N;
	for (int i = 0; i < N; ++i) {
		int addr, next; char ch; getchar();
		scanf("%d %c %d", &addr, &ch, &next);
		hash_map[addr] = next;
	}

	visit[s1] = true;
	int addr = s1;
	for ( ; addr != -1; addr = hash_map[addr]) visit[addr] = true;
	for (addr = s2; addr != -1; addr = hash_map[addr]) {
		if (visit[addr]) { printf("%05d\n", addr); return; }
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
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
*/