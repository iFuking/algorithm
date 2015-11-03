#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3) return res;

		sort(nums.begin(), nums.end());
		set<vector<int>> ans;
		for (int i = 0; i < nums.size()-2; ++i) {
			if (i>0 && nums[i]==nums[i-1]) continue;

			int head = i+1, tail = nums.size()-1;
			int target = 0-nums[i];

			while (head < tail) {
				vector<int> triple;
				int two_sum = nums[head]+nums[tail];
				if (two_sum < target) ++head;
				else if (two_sum > target) --tail;
				else {
					triple.push_back(nums[i]);
					triple.push_back(nums[head]);
					triple.push_back(nums[tail]);
					ans.insert(triple);
					while (++head<tail && nums[head]==nums[head-1]) ;
					while (head<--tail && nums[tail]==nums[tail+1]) ;
				}
			}
		}

		set<vector<int>>::iterator iter = ans.begin();
		for ( ; iter != ans.end(); ++iter) res.push_back(*iter);
		return res;
	}
};

int main()
{
	int s[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> sum(s, s+109);
	Solution sol;
	sol.threeSum(sum);
	return 0;
}