#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	double log10_fact(int n)
	{
		double ans = 0.0;
		for (int i = 1; i <= n; ++i) ans += log10(1.0*i);
		return ans;
	}

	int combination(int n, int r)
	{
		if (r > n/2) r = n-r;
		double log_com = log10_fact(n)-log10_fact(r)-log10_fact(n-r);
		return ceil(pow(10, log_com)-0.5);
	}

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
		for (int i = 0; i < numRows; ++i) {
			vector<int> v;
			for (int j = 0; j <= i; ++j) v.push_back(combination(i, j));
			ans.push_back(v);
		}
		return ans;
    }
};

int main()
{
	Solution sol;
	sol.generate(5);
	return 0;
}