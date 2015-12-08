#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		vector<int>::iterator iter = nums.begin(), it = iter;
		++iter;
		while (iter != nums.end()) {
			if (*iter == *it) iter = nums.erase(iter);
			else { ++iter; ++it; }
		}
		return nums.size();
    }
};

int main()
{
	Solution sol;
	int a[] = {1, 2, 2};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	sol.removeDuplicates(v);
	return 0;
}