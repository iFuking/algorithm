#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//    void rotate(vector<int>& nums, int k) {
//        int last = nums.size()-1;
//        while (k--) {
//            nums.insert(nums.begin(), nums[last]);
//            nums.pop_back();
//        }
//        return;
//    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(),nums.begin() + n - k);
        reverse(nums.begin() + n - k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    sol.rotate(v, 3);
    return 0;
}
