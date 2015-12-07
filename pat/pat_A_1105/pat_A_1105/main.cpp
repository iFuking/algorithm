#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 10;

bool cmp(const int &n1, const int &n2) { return n1 > n2; }

void solve()
{
	int N; cin >> N;
	vector<int> arr(maxn);
	for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end(), cmp);

	int min_delta = maxn, m, n;
	for (int i = 1; i <= sqrt(1.0*N); ++i) {
		if (N%i==0 && abs(i-N/i)<min_delta) {
			min_delta = abs(i-N/i);
			m = max(i, N/i); n = min(i, N/i);
		}
	}

	vector<vector<int>> mat(m, vector<int>(n));
	int left = 0, right = n-1, up = 0, down = m-1;
	int index = 0;
	while (true) {
		for (int i = left; i <= right; ++i) mat[up][i] = arr[index++];
		++up; if (up > down) break;
		for (int i = up; i <= down; ++i) mat[i][right] = arr[index++];
		--right; if (right < left) break;
		for (int i = right; i >= left; --i) mat[down][i] = arr[index++];
		--down; if (down < up) break;
		for (int i = down; i >= up; --i) mat[i][left] = arr[index++];
		++left; if (left > right) break;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n-1; ++j) printf("%d ", mat[i][j]);
		printf("%d\n", mat[i][n-1]);
	}
	return;
}

int main()
{
	solve();
	return 0;
}