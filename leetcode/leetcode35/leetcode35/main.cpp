#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
		while (left <= right) {
			int mid = (left+right) >> 1;
			if (target < nums[mid]) right = mid-1;
			else if (target > nums[mid]) left = mid+1;
			else return mid;
		}
		return left;
    }
};

int main()
{
	Solution sol;
	int a[] = {1, 3, 5, 6};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	sol.searchInsert(v, 5);
	return 0;
}