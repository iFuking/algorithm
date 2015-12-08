#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		if (nums.size() < 2) return true;
		int index = nums.size()-1;
		for (int i = index-1; i >= 0; --i) {
			if (nums[i]+i >= index) index = i;
		}
		if (index == 0) return true;
		return false;
    }
};

int main()
{
	Solution sol;
	int a[] = {3, 2, 1, 0, 4};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	sol.canJump(v);
	return 0;
}