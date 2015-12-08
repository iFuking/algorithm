#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int head = 0, tail = 0, sum = 0;
		int ans = nums.size();
		for ( ; tail < nums.size(); ++tail) {
			sum += nums[tail];
			if (sum >= s) {
				if (tail-head < ans) ans = tail-head;
				while (sum-nums[head] >= s) {
					sum -= nums[head++];
					if (tail-head < ans) ans = tail-head;
				}
			}
		}
		if (sum < s) return 0;
		return ans+1;
    }
};

int main()
{
	Solution sol;
	int a[] = {2, 3, 1, 2, 4, 3};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	sol.minSubArrayLen(7, v);
	return 0;
}