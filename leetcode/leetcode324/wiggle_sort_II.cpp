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

    void wiggleSort(vector<int>& nums) {
        srand((unsigned int)time(NULL));

        int nsize = nums.size();
        if (nsize & 1) ++nsize;
        // auto p = nums.begin() + nums.size()/2;
        // nth_element(nums.begin(), p, nums.end());
        // int median = *p;
        int median = kth_largest(nums, 0, nums.size()-1, nsize/2);

        // three-way-partition
        // partition nums, less than pivot, equal to pivot, greater than pivot
        // int left = 0, right = nums.size()-1, k = 0;
        // while (k <= right) {
        //     if (nums[k] < median) {
        //         swap(nums[left], nums[k]);
        //         ++left; ++k;
        //     } else if (nums[k] > median) {
        //         swap(nums[k], nums[right]);
        //         --right;
        //     } else ++k;
        // }


        // 0 1 2 3 4 5 6 7 8 9
        // . M . M . L . L . L
        // S . S . S . S . M .
        // (1) elements smaller than the 'median' are put into the last even slots
        // (2) elements larger than the 'median' are put into the first odd slots
        // (3) the medians are put into the remaining slots.
        // space complexity is O(N)
        // constant space complexity using 'three-way-partition'
        vector<int> v(nums.size());
        int n = nums.size();
        int less = n-1-(n&1?0:1), greater = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i]<median && less>=0) {
                v[less] = nums[i];
                less -= 2;
            } else if (nums[i]>median && greater<n) {
                v[greater] = nums[i];
                greater += 2;
            }
        }

        while (less >= 0) {
            v[less] = median;
            less -= 2;
        }
        while (greater < n) {
            v[greater] = median;
            greater += 2;
        }

        nums = v;
        return;
    }
};

int main() {
    int a[] = {2, 1, 1, 3, 2, 1};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol; sol.test_three_way_partition(v);
    return 0;
}