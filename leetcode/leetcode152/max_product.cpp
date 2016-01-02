#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // max_p, min_p means max_p and min_p product among the subarrays whose last element is nums[i]
        int max_p = nums[0], min_p = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmp_max = max_p;
            max_p = max(nums[i], max(max_p*nums[i], min_p*nums[i]));
            min_p = min(nums[i], min(tmp_max*nums[i], min_p*nums[i]));
            ans = max(ans, max_p);
        }
        return ans;
    }
};


int main()
{
    int a[] = {0, 3};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.maxProduct(v) << endl;
    return 0;
}
