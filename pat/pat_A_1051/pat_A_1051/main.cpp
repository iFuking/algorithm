#include <iostream>
#include <stack>
using namespace std;

const int maxn = 1010;
int M, N, K;
int seq[maxn];

void solve()
{
	cin >> M >> N >> K;
	while (K--)
	{
		for (int i = 0; i < N; ++i) scanf("%d", &seq[i]);
		stack<int> st; int cnt = 0;
		for (int i = 1; i<=N && cnt<N; ++i)
		{
			st.push(i);
			if (st.size() > M) break;
			while (st.size()>0 && st.top()==seq[cnt]) { st.pop(); ++cnt; }
		}
		if (cnt == N) printf("YES\n");
		else printf("NO\n");
	}
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}