#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int pre = 0x80000000, next;
        int peak;
        for (int i = 0; i < nums.size(); ++i) {
            next = i<nums.size()-1 ? nums[i+1] : 0x80000000;
            if (nums[i]>pre && nums[i]>next) { peak = i; break; }
            pre = nums[i];
        }
        return peak;
    }
};

int main()
{
    int a[] = {-21474836};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.findPeakElement(v) << endl;
    return 0;
}
