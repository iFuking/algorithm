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

	bool prePermutation(vector<int>& nums) {
		if (nums.size() < 2) return false;
		for (int i = nums.size()-2; i >= 0; --i) {
			int ii = i+1;
			if (nums[i] > nums[ii]) {
				int j = nums.size();
				while (nums[i] <= nums[--j]) ;
				swap(nums[i], nums[j]);
				for (int k = 0; k < (nums.size()-ii)/2; ++k) swap(nums[ii+k], nums[nums.size()-1-k]);
				return true;
			}
		}
		return false;
	}

    void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		for (int i = nums.size()-2; i >= 0; --i) {
			int ii = i+1;
			if (nums[i] < nums[ii]) {
				int j = nums.size();
				while (nums[i] >= nums[--j]) ;
				swap(nums[i], nums[j]);
				for (int k = 0; k < (nums.size()-ii)/2; ++k) swap(nums[ii+k], nums[nums.size()-1-k]);
				return;
			}
			if (i == 0) sort(nums.begin(), nums.end());
		}
		return;
    }
};

bool cmp(const int &m, const int &n) { return m > n; }

int main()
{
	int a[] = {1, 3, 2, 9};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	sort(v.begin(), v.end(), cmp);
	Solution sol;
	do {
		for (int i = 0; i < v.size(); ++i) printf("%d ", v[i]);
		printf("\n");
	} while (sol.prePermutation(v));
	return 0;
}