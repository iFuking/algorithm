#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec;
        int i = 0, j = 0;
        while (i<m && j<n) {
            if (nums1[i] < nums2[j]) vec.push_back(nums1[i++]);
            else vec.push_back(nums2[j++]);
        }
        if (i == m) {
            for (int k = j; k < n; ++k) vec.push_back(nums2[k]);
        } else if (j == n) {
            for (int k = i; k < m; ++k) vec.push_back(nums1[k]);
        }
        nums1 = vec;
        return;
    }
};


int main()
{
    int a[] = {1, 2, 2, 7};
    int b[] = {0, 2, 4, 6, 8};
    vector<int> nums1(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> nums2(b, b+sizeof(b)/sizeof(b[0]));
    Solution sol;
    sol.merge(nums1, sizeof(a)/sizeof(a[0]), nums2, sizeof(b)/sizeof(b[0]));
    return 0;
}
