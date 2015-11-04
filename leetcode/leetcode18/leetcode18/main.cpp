#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
		if (nums.size() < 4) return ans;
		
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-3; ++i) {
			if (i>0 && nums[i]==nums[i-1]) continue;
			for (int j = i+1; j < nums.size()-2; ++j) {
				if (j>i+1 && nums[j]==nums[j-1]) continue;
				int head = j+1, tail = nums.size()-1;
				while (head < tail) {
					vector<int> res;
					int four_sum = nums[i]+nums[j]+nums[head]+nums[tail];
					if (four_sum < target) {
						while (++head<tail && nums[head]==nums[head-1]) ;
					} else if (four_sum > target) {
						while (head<--tail && nums[tail]==nums[tail+1]) ;
					} else {
						res.push_back(nums[i]); res.push_back(nums[j]);
						res.push_back(nums[head]); res.push_back(nums[tail]);
						ans.push_back(res);
						while (++head<tail && nums[head]==nums[head-1]) ;
						while (head<--tail && nums[tail]==nums[tail+1]) ;
					}
				}
			}
		}
		return ans;
    }
};

int main()
{
	int a[] = {-3, -2, -1, 0, 0, 1, 2, 3};
	vector<int> nums(a, a+8);
	Solution sol;
	sol.fourSum(nums, 0);
	return 0;
}