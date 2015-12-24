#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        vector<int> ans;
        ans.push_back(nums[0]); ans.push_back(nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i-1] != nums[i-2]) ans.push_back(nums[i]);
            else if (nums[i] != nums[i-1]) ans.push_back(nums[i]);
        }
        nums = ans;
        return nums.size();
    }
};


int main()
{
    int a[] = {1, 1, 1, 2, 2, 3};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.removeDuplicates(v) << endl;
    return 0;
}
