#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            // sliding window
            if (i > k) s.erase(nums[i-k-1]);

            // |x-nums[i]| <= t  ->  -t+nums[i]<= x <= t+nums[i]
            // meet lower bound 
            set<int>::iterator iter = s.lower_bound(-t+nums[i]);

            // meet upper bound, *iter<=t+nums[i] may overflow
            if (iter!=s.end() && *iter-t<=nums[i]) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol;
    int a[] = {1, 99, 1, 2};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    cout << sol.containsNearbyAlmostDuplicate(v, 1, 1) << endl;
    return 0;
}