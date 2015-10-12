#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 305;
int fa[maxn][maxn], sa[maxn][maxn];

class Cards {
public:
	// 先手获得的分数
	int f(vector<int> A, int i, int j)
	{
		if (fa[i][j] >= 0) return fa[i][j];
		else if (i == j) return fa[i][j] = A[i];
		return fa[i][j] = max(A[i]+s(A, i+1, j), A[j]+s(A, i, j-1));
	}

	// 后手获得的分数
	int s(vector<int> A, int i, int j)
	{
		if (sa[i][j] >= 0) return sa[i][j];
		else if (i == j) return sa[i][j] = 0;
		return sa[i][j] = min(f(A, i+1, j), f(A, i, j-1));
	}

    int cardGame(vector<int> A, int n) {
		if (n == 0) return 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) fa[i][j] = sa[i][j] = -1;
		}
		return max(f(A, 0, n-1), s(A, 0, n-1));
    }
};

int main()
{
	Cards sol;
	int a[] = {1, 2, 100, 4};
	vector<int> arr(a, a+4);
	cout << sol.cardGame(arr, arr.size()) << endl;
	return 0;
}