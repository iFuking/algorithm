#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	long long abs(long long n) { return n>0 ? n : 0-n; }

	int division(long long dividend, int divisor)
	{
		int sign = 1;
		if (dividend>0&&divisor<0 || dividend<0&&divisor>0) sign = -1;
		long long a = abs(dividend), b = abs(divisor);
		int ans = 0;
		for (int i = 31; i>=0 && a>=b; --i) {
			if ((b<<i) <= a) {
				a -= (b<<i);
				ans += (1<<i);
			}
		}
		if (sign < 0) return 0-ans;
		return ans;
	}

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
		if (nums.size() < 1) return ans;

		long long product = 1;
		int zero_cnt = 0, zero_index;
		for (int i = 0; i < nums.size(); ++i) {
			if (zero_cnt > 1) break;
			if (nums[i] == 0) { ++zero_cnt; zero_index = i; }
			else product *= nums[i];
		}
		if (zero_cnt == 0) for (int i = 0; i < nums.size(); ++i) ans.push_back(division(product, nums[i]));
		else if (zero_cnt > 1) for (int i = 0; i < nums.size(); ++i) ans.push_back(0);
		else {
			for (int i = 0; i < nums.size(); ++i) {
				if (i == zero_index) ans.push_back(product);
				else ans.push_back(0);
			}
		}
		return ans;
    }
};

int main()
{
	int a[] = {0, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	sol.productExceptSelf(v);
	return 0;
}