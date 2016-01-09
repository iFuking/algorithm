#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		int color[3] = {0};
		for (int i = 0; i < nums.size(); ++i) ++color[nums[i]];
		for (int i = 0, j = 0; i < 3; ++i) {
			while (color[i]--) nums[j++] = i;
		}
		return;
    }
};

int main()
{
	Solution sol;
	int a[] = {1, 2, 0, 1, 2, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	sol.sortColors(v);
	return 0;
}