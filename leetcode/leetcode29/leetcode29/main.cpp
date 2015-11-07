#include <iostream>
using namespace std;

const int MAX_INT = 0x7fffffff;

class Solution {
public:
	int abs(int x) { return x > 0 ? x : 0-x; }

    int divide(int dividend, int divisor) {
        if (divisor == 0) return MAX_INT;

		int sign = 1;
		if (dividend<0&&divisor>0 || dividend>0&&divisor<0) sign = -1;
		dividend = abs(dividend); divisor = abs(divisor);
		int ans = 0;
		while (dividend >= divisor) {
			dividend -= divisor;
			++ans;
		}
		if (sign < 0) return 0-ans;
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