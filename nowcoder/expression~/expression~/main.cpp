#include <iostream>
#include <string>
using namespace std;

const int M = 1e4 + 7;
const int maxn = 305;
int t[maxn][maxn], f[maxn][maxn];

class Expression {
public:
	int countWays(string exp, int len, int l, int r, int ret) {
		if (ret==0 && f[l][r]>=0) return f[l][r]%M;
		else if (ret==1 && t[l][r]>=0) return t[l][r]%M;
		else if (l == r) {
			if (ret == 0) return f[l][r] = (exp[l]=='0' ? 1 : 0);
			else return t[l][r] = (exp[l]=='1' ? 1 : 0);
		}

		int ans = 0;
		for (int i = l+1; i < r; i += 2) {
			f[l][i-1] = countWays(exp, len, l, i-1, 0);
			f[i+1][r] = countWays(exp, len, i+1, r, 0);
			t[l][i-1] = countWays(exp, len, l, i-1, 1);
			t[i+1][r] = countWays(exp, len, i+1, r, 1);
			if (ret == 0) {
				if (exp[i] == '&') ans += f[l][i-1]*f[i+1][r]%M + f[l][i-1]*t[i+1][r]%M + t[l][i-1]*f[i+1][r]%M;
				else if (exp[i] == '|') ans += f[l][i-1]*f[i+1][r]%M;
				else if (exp[i] == '^') ans += f[l][i-1]*f[i+1][r]%M + t[l][i-1]*t[i+1][r]%M;
			} else {
				if (exp[i] == '&') ans += t[l][i-1]*t[i+1][r]%M;
				else if (exp[i] == '|') ans += f[l][i-1]*t[i+1][r]%M + t[l][i-1]*f[i+1][r]%M + t[l][i-1]*t[i+1][r]%M;
				else if (exp[i] == '^') ans += f[l][i-1]*t[i+1][r]%M + t[l][i-1]*f[i+1][r]%M;
			}
		}
		ret==0 ? f[l][r]=ans%M : t[l][r]=ans%M;
		return ans%M;
	}

    int countWays(string exp, int len, int ret) {
		for (int i = 0; i < len; ++i) {
            if (i&1==0 && (exp[i]!='0'&&exp[i]!='1')) return 0;
            else if (i&1==1 && (exp[i]!='&'&&exp[i]!='|'&&exp[i]!='^')) return 0;
        }

		for (int i = 0; i < len; ++i) {
			for (int j = i; j < len; ++j) f[i][j] = t[i][j] = -1;
		}
		return countWays(exp, len, 0, len-1, ret)%M;
    }
};

int main()
{
	Expression sol;
	cout << sol.countWays("0^1|1^0&1&1^0^0|0^0&1&0&1|1", 27, 1) << endl;
	return 0;
}