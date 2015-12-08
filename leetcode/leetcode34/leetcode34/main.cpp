#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int b_search(vector<int>& nums, int target, bool flag)
	{
		int left = 0, right = nums.size()-1;
		bool find = false;
		while (left <= right) {
			int mid = (left+right) >> 1;
			if (target < nums[mid]) right = mid-1;
			else if (target > nums[mid]) left = mid+1;
			else {
				find = true;
				if (!flag) right = mid-1;
				else left = mid+1;
			}
		}
		if (!find) return -1;
		if (!flag) return left;
		return right;
	}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
		ans.push_back(b_search(nums, target, false));
		ans.push_back(b_search(nums, target, true));
		return ans;
    }
};

int main()
{
	Solution sol;
	int a[] = {5, 7, 7, 8, 8, 10};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	sol.searchRange(v, 10);
	return 0;
}