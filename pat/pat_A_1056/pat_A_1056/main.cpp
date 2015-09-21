#include <iostream>
#include <queue>
using namespace std;

const int maxn = 1010;
int N, G;
int w[maxn], order[maxn];
int m_rank[maxn], lose_order[maxn];

void solve()
{
	cin >> N >> G;
	for (int i = 0; i < N; ++i) scanf("%d", &w[i]);
	for (int i = 0; i < N; ++i) scanf("%d", &order[i]);

	queue<int> q;
	for (int i = 0; i < N; ++i) q.push(order[i]);

	int len_win = 0, len_lose = 0;
	for (int i=0, q_size=q.size(); i < q_size; i += G) {
		int sub_max = -1, flag;
		for (int j = i; j<G+i && j<q_size; ++j) {
			if (w[order[j]] > sub_max) sub_max = w[flag=order[j]];
		}
		for (int j = i; j<G+i && j<q_size; ++j) {
			if (w[order[j]] < sub_max) {
				q.pop();
				lose_order[len_lose++] = order[j];
			} else {
				int weight = q.front();
				q.pop(); q.push(weight);
				order[len_win++] = weight;
			}
		}
		if ((q_size%G&&i==q_size-q_size%G) || (!(q_size%G)&&i==q_size-G)) {
			q_size = q.size();
			for (int j = 0; j < len_lose; ++j) m_rank[lose_order[j]] = q_size+1;
			i = 0-G; len_win = 0; len_lose = 0;
		}
		if (q_size == 1) { m_rank[order[0]] = 1; break; }
	}

	for (int i = 0; i < N-1; ++i) printf("%d ", m_rank[i]);
	printf("%d\n", m_rank[N-1]);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}


/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

6 3
25 18 0 46 37 3
4 0 5 1 2 3
*/