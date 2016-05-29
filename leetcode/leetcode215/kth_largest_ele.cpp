#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int partition(vector<int> &v, int left, int right) {
        int i = left, j = right;
        // randomly select
        int idx = rand() % (right-left+1);
        int pivot = v[i+idx];
        swap(v[i], v[i+idx]);

        while (i < j) {
            while (i<j && pivot>=v[j]) --j;
            if (i < j) swap(v[i++], v[j]);
            while (i<j && v[i]>=pivot) ++i;
            if (i < j) swap(v[i], v[j--]);
        }
        return i;
    }

    int kth_largest(vector<int> &v, int left, int right, int k) {
        if (left == right) return v[left];
        int i = partition(v, left, right);
        int j = i-left+1;
        if (k <= j) return kth_largest(v, left, i, k);
        return kth_largest(v, i+1, right, k-j);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return kth_largest(nums, 0, nums.size()-1, k);
    }
};

int main() {
    int a[] = {3, 2, 1, 5, 6, 4};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.findKthLargest(v, 3) << endl;
    return 0;
}