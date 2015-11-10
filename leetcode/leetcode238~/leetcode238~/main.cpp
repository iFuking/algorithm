#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
		if (nums.size() < 2) return ans;

		int product = 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (i == 0) ans.push_back(1);
			else {
				product *= nums[i-1];
				ans.push_back(product);
			}
		}

		product = 1;
		for (int i = nums.size()-2; i >= 0; --i) {
			 product *= nums[i+1];
			 ans[i] *= product;
		}
		return ans;
    }
};

int main()
{
	int a[] = {0, 0, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	sol.productExceptSelf(v);
	return 0;
}