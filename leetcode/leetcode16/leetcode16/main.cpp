#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int closest = 0x3f3f3f3f, ans;
		for (int i = 0; i < nums.size()-2; ++i) {
			if (i>0 && nums[i]==nums[i-1]) continue;
			int head = i+1, tail = nums.size()-1;
			while (head < tail) {
				int three_sum = nums[i]+nums[head]+nums[tail];
				int close = abs(three_sum-target);
				if (three_sum-target < 0) {
					while (++head<tail && nums[head]==nums[head-1]) ;
				} else if (three_sum-target > 0) {
					while (head<--tail && nums[tail]==nums[tail+1]) ;
				} else return target;
				if (close < closest) { closest = close; ans = three_sum; }
				else break;
			}
		}
		return ans;
    }
};

int main()
{
	int v[] = {-1, 2, 1, -4};
	vector<int> nums(v, v+4);
	Solution sol;
	sol.threeSumClosest(nums, 1);
	return 0;
}