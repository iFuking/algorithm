#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool has_next = false;
		if (next_permutation(nums.begin(), nums.end())) has_next = true;
		if (!has_next) sort(nums.begin(), nums.end());
		return;
    }
};

int main()
{
	int a[] = {3, 2, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	sol.nextPermutation(v);
	return 0;
}