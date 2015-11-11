#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void swap(int &n1, int &n2)
	{
		int n = n1; n1 = n2; n2 = n;
		return;
	}

	bool next_permutation(vector<int>& nums)
	{
		for (int i = nums.size()-2; i >= 0; --i) {
			int ii = i+1;
			if (nums[i] < nums[ii]) {
				int j = nums.size();
				while (nums[i] >= nums[--j]) ;
				swap(nums[i], nums[j]);
				for (int k = 0; k < (nums.size()-ii)/2; ++k) swap(nums[ii+k], nums[nums.size()-1-k]);
				return true;
			}
		}
		return false;
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
		if (nums.size() < 1) return ans;
		sort(nums.begin(), nums.end());
		do {
			ans.push_back(nums);
		} while (next_permutation(nums));
		return ans;
    }

	/*vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
		if (nums.size() < 1) return ans;
		sort(nums.begin(), nums.end());
		do {
			ans.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return ans;
    }*/
};

int main()
{
	int a[] = {1, 2, 3};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	sol.permute(v);
	return 0;
}