#include <iostream>
using namespace std;

const int MAX_INT = 0x7fffffff;

class Solution {
public:
	long long abs(long long x) { return x > 0 ? x : 0-x; }

    int divide(int dividend, int divisor) {
        if (divisor == 0) return MAX_INT;

		int sign = 1;
		if (dividend<0&&divisor>0 || dividend>0&&divisor<0) sign = -1;
		long long x = abs(dividend), y = abs(divisor);
		long long ans = 0;
		
		for (int i = 31; i>=0 && x>=y; --i) {
			if ((y<<i) <= x) {
				x -= (y<<i);
				ans += (1LL<<i);
			}
		}

		if (sign < 0) return 0-ans;
		if (ans > MAX_INT) return MAX_INT;
		return ans;
    }
};

int main()
{
	Solution sol;
	while (true) {
		int dividend, divisor; cin >> dividend >> divisor;
		cout << sol.divide(dividend, divisor) << endl;
	}
	return 0;
}