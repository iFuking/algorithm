#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0) return false;
		set<int> s;
		for (int i = 0; i < nums.size(); ++i) s.insert(nums[i]);
		if (s.size() < nums.size()) return true;
		return false;
    }
};

int main()
{
	Solution sol;
	int a[] = {1, 2, 4, 5, 6, 7, 8, 3, 5, 9};
	vector<int> arr(a, a+10);
	cout << sol.containsDuplicate(arr) << endl;
	return 0;
}