#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> dp(nums.size());
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size()-1; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }

        int max_rob = dp[nums.size()-2];


        // for (int i = 0; i < dp.size(); ++i) {
        //     printf("%d ", dp[i]);
        // }
        // printf("\n");
        

        dp[1] = nums[1]; dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }


        // for (int i = 0; i < dp.size(); ++i) {
        //     printf("%d ", dp[i]);
        // }
        // printf("\n");


        return max(max_rob, dp[nums.size()-1]);
    }
};

int main() {
    int a[] = {2, 1, 1, 1};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));

    Solution sol;
    cout << sol.rob(v) << endl;
    return 0;
}