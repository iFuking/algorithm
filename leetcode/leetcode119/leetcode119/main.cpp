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

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
		for (int i = 0; i <= rowIndex; ++i) ans.push_back(combination(rowIndex, i));
		return ans;
    }
};

int main()
{
	Solution sol;
	return 0;
}