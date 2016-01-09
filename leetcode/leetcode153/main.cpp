#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int b_search(vector<int>& nums)
    {
        int left = 0, right = nums.size()-1;
        int ans = 0x3f3f3f3f;
        while (left <= right) {
            int mid = (left+right) >> 1;
            if (nums[mid] > nums[right]) left = mid+1;
            else if (nums[mid] < nums[right]) right = mid-1;
            else --right;
            if (nums[mid] < ans) ans = nums[mid];
        }
        return ans;
    }

    int findMin(vector<int>& nums) {
//        int ans = 0x3f3f3f3f;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (nums[i] < ans) ans = nums[i];
//        }
//        return ans;
        return b_search(nums);
    }
};

int main()
{
    int a[] = {1, 3, 3};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.findMin(v) << endl;
    return 0;
}
