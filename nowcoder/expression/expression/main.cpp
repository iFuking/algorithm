#include <iostream>
#include <string>
using namespace std;

const int M = 1e4 + 7;

class Expression {
public:
	int countWays(string exp, int len, int l, int r, int ret) {
		if (l == r) {
			if (ret == 0) return exp[l]=='0' ? 1 : 0;
			else return exp[l]=='1' ? 1 : 0;
		}
		int ans = 0;
		for (int i = l+1; i < r; i += 2) {
			if (ret == 0) {
				if (exp[i] == '&') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 0)%M + \
					countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 1)%M + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 0)%M;
				else if (exp[i] == '|') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 0)%M;
				else if (exp[i] == '^') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 0)%M + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 1)%M;
			} else {
				if (exp[i] == '&') ans += countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 1)%M;
				else if (exp[i] == '|') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 1)%M + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 0)%M + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 1)%M;
				else if (exp[i] == '^') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 1)%M + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 0)%M;
			}
		}
		return ans%M;
	}

    int countWays(string exp, int len, int ret) {
		for (int i = 0; i < len; ++i) {
			if (i&1==0 && (exp[i]!='0'&&exp[i]!='1')) return 0;
			else if (i&1==1 && (exp[i]!='&'&&exp[i]!='|'&&exp[i]!='^')) return 0;
		}
		return countWays(exp, len, 0, len-1, ret)%M;
    }
};

int main()
{
	Expression sol;
	cout << sol.countWays("1^0^0&1&0^0|0|1&1", 17, 0) << endl;
	return 0;
}