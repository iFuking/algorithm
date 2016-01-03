#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ) {
            if (nums[i]>0 && nums[i]<=nums.size() && nums[i]!=i+1 && nums[i]!=nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            } else ++i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};

int main()
{
    int a[] = {3, 4, 3, 1, 1};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.firstMissingPositive(v) << endl;
	return 0;
}
