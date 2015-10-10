#include <iostream>
#include <string>
using namespace std;

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
				if (exp[i] == '&') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 0) + \
					countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 1) + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 0);
				else if (exp[i] == '|') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 0);
				else if (exp[i] == '^') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 0) + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 1);
			} else {
				if (exp[i] == '&') ans += countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 1);
				else if (exp[i] == '|') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 1) + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 0) + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 1);
				else if (exp[i] == '^') ans += countWays(exp, len, l, i-1, 0)*countWays(exp, len, i+1, r, 1) + \
					countWays(exp, len, l, i-1, 1)*countWays(exp, len, i+1, r, 0);
			}
		}
		return ans;
	}

    int countWays(string exp, int len, int ret) {
		for (int i = 0; i < len; ++i) {
			if (i&1==0 && (exp[i]!='0'&&exp[i]!='1')) return 0;
			else if (i&1==1 && (exp[i]!='&'&&exp[i]!='|'&&exp[i]!='^')) return 0;
		}
		return countWays(exp, len, 0, len-1, ret);
    }
};

int main()
{
	Expression sol;
	cout << sol.countWays("0&1|1&1^1^0", 11, 0) << endl;
	return 0;
}