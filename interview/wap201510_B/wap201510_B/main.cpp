#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 505;
int grid[maxn][maxn];
// s[i][j]表示从[i, j]点开始不穿越能取到的最大值
// t[i][j]表示从[i, j]点开始穿越能取到的最大值
long long s[maxn][maxn], t[maxn][maxn];
int m, n;

void solve()
{
	scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &grid[i][j]);
	}

    memset(s, 0, sizeof(s));
	memset(t, 0, sizeof(t));

    long long sum, ans1, ans2;
    bool flag;
    for (int j = n-1; j >= 0; --j)
	{
        for (int i = 0; i < m; ++i)
		{
            sum = 0;
            if (grid[i][j] == -1) {
                //该点不可到达
                s[i][j] = t[i][j] = -1;
                continue;
            }
            ans1 = -1;  //记录不穿越的最大值
            ans2 = -1;  //记录穿越的最大值
            flag = false;   //记录是否碰到不可到达的点
            //往上走
            for (int k = i; k >= 0; --k) {
                if (grid[k][j] == -1) { flag = true; break; }
                sum += grid[k][j];
                //在当前列未穿越
                if (s[k][j + 1]!=-1 && s[k][j+1]+sum>ans1) ans1 = s[k][j+1]+sum;
                //如果取后面的穿越最大值，那么前面的sum全部清0
                if (t[k][j+1]!=-1 && t[k][j+1]>ans2) ans2 = t[k][j + 1];
            }
            if (!flag) {
                sum = 0;
                for (int k = m - 1; k > i; --k) {
                    if (grid[k][j] == -1) { flag = true; break; }
                    sum += grid[k][j];
                    //在当前列有穿越
                    if (s[k][j+1]!=-1 && s[k][j+1]+sum>ans2) ans2 = s[k][j+1]+sum;
                    if (t[k][j+1]!=-1 && t[k][j+1]>ans2) ans2 = t[k][j+1];
                }
            }

            //往下走
            sum = 0;
            flag = false;
            for (int k = i; k < m; ++k) {
                if (grid[k][j] == -1) { flag = true; break; }
                sum += grid[k][j];
                if (s[k][j+1]!=-1 && s[k][j+1]+sum>ans1) ans1 = s[k][j+1]+sum;
                if (t[k][j+1]!=-1 && t[k][j+1]>ans2) ans2 = t[k][j+1];
            }
            if (!flag) {
                sum = 0;
                for (int k = 0; k < i; ++k) {
                    if (grid[k][j] == -1) { flag = true; break; }
                    sum += grid[k][j];
                    if (s[k][j+1]!=-1 && s[k][j+1]+sum>ans2) ans2 = s[k][j+1]+sum;
                    if (t[k][j+1]!=-1 && t[k][j+1]>ans2) ans2 = t[k][j+1];
                }
            }

            s[i][j] = ans1;
            t[i][j] = ans2;
        }
    }

    //查询最大值
    long long ans = -1;
    for (int i = 0; i < m; ++i) {
        if (s[i][0] > ans) ans = s[i][0];
        if (t[i][0] > ans) ans = t[i][0];
    }

    printf("%lld\n", ans);
	return;
}

int main()
{
    solve();
    return 0;
}

/*
4 4
-1 4 5 1
2 -1 2 4
3 3 -1 3
4 2 1 2

4 4
-1 4 5 1
2 -1 2 4
3 3 -1 -1
4 2 1 2
*/