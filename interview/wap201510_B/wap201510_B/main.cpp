#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 505;
int grid[maxn][maxn];
// s[i][j]��ʾ��[i, j]�㿪ʼ����Խ��ȡ�������ֵ
// t[i][j]��ʾ��[i, j]�㿪ʼ��Խ��ȡ�������ֵ
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
                //�õ㲻�ɵ���
                s[i][j] = t[i][j] = -1;
                continue;
            }
            ans1 = -1;  //��¼����Խ�����ֵ
            ans2 = -1;  //��¼��Խ�����ֵ
            flag = false;   //��¼�Ƿ��������ɵ���ĵ�
            //������
            for (int k = i; k >= 0; --k) {
                if (grid[k][j] == -1) { flag = true; break; }
                sum += grid[k][j];
                //�ڵ�ǰ��δ��Խ
                if (s[k][j + 1]!=-1 && s[k][j+1]+sum>ans1) ans1 = s[k][j+1]+sum;
                //���ȡ����Ĵ�Խ���ֵ����ôǰ���sumȫ����0
                if (t[k][j+1]!=-1 && t[k][j+1]>ans2) ans2 = t[k][j + 1];
            }
            if (!flag) {
                sum = 0;
                for (int k = m - 1; k > i; --k) {
                    if (grid[k][j] == -1) { flag = true; break; }
                    sum += grid[k][j];
                    //�ڵ�ǰ���д�Խ
                    if (s[k][j+1]!=-1 && s[k][j+1]+sum>ans2) ans2 = s[k][j+1]+sum;
                    if (t[k][j+1]!=-1 && t[k][j+1]>ans2) ans2 = t[k][j+1];
                }
            }

            //������
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

    //��ѯ���ֵ
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