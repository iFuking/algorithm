#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int larger(int a, int b) {
		return a > b ? a : b;
	}

    int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];

		vector<int> dp(nums.size()+1); dp[0] = 0;
		int largestSum = 0x80000000;
		for (int i = 1; i < nums.size()+1; ++i) {
			dp[i] = larger(dp[i-1]+nums[i-1], 0);
			if (dp[i] > largestSum) largestSum = dp[i];
		}
		if (largestSum) return largestSum;
		
		largestSum = 0x80000000;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > largestSum) largestSum = nums[i];
		}
		return largestSum;
    }
};

int main(int argc, char *argv[]) {
	int anums[] = {-3, -2, -2, -3};
	vector<int> vnums(anums, anums+4);
	Solution sol;
	cout << sol.maxSubArray(vnums) << endl;
	return 0;
}