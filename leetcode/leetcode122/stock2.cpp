#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int max_profit = 0, min_price = prices[0], max_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < max_price) {
                max_profit += (max_price-min_price);
                min_price = prices[i];
                max_price = prices[i];
                continue;
            } else max_price = prices[i];
            if (prices[i] < min_price) min_price = prices[i];
        }
        return max_profit+max_price-min_price;
    }
};


int main()
{
    int a[] = {2, 3};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.maxProfit(v) << endl;
    return 0;
}
