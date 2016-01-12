#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) return 0;

        // left[i] records the max profit from prices[0]~prices[i]
        vector<int> left(prices.size(), 0);
        int local_min = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            left[i] = max(left[i-1], prices[i]-local_min);
            local_min = min(local_min, prices[i]);
        }

        // right[i] records the max profit from prices[i]~prices[prices.size()-1]
        vector<int> right(prices.size(), 0);
        int local_max = prices[prices.size()-1];
        for (int i = prices.size()-2; i >= 0; --i) {
            right[i] = max(right[i+1], local_max-prices[i]);
            local_max = max(local_max, prices[i]);
        }

        int profit_max = 0;
        for (int i = 0; i < prices.size(); ++i) profit_max = max(profit_max, left[i]+right[i]);
        return profit_max;
    }
};

int main()
{
	int a[] = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	cout << sol.maxProfit(v) << endl;
	return 0;
}
