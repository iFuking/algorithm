#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; vector<int> v;

        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front()+k==i) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()]<nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            if (i >= k-1) {
                v.push_back(nums[dq.front()]);
            }
        }
        return v;
    }
};

int main() {
    int a[] = {1, 3, -1, -3, -2, 3, 6, 7};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    Solution sol;
    v = sol.maxSlidingWindow(v, 3);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}