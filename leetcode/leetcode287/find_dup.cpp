#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size()-1;
        while (left <= right) {
            int mid = (left+right) >> 1;
            int cnt = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mid) ++cnt;
            }
            if (cnt <= mid) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};

int main()
{
	int a[] = {1, 3, 4, 2, 2};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	cout << sol.findDuplicate(v) << endl;
	return 0;
}
