#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int find_pivot(vector<int>& nums)
//    {
//        int left = 0, right = nums.size()-1;
//        while (left <= right) {
//            int mid = (left+right)>>1;
//            if (nums[mid] > nums[right]) left = mid+1;
//            else if (nums[mid] < nums[right]) right = mid;
//            else return mid;
//        }
//        return -1;
//    }
//
//    int b_search(vector<int>& nums, int left, int right, int target)
//    {
//        while (left <= right) {
//            int mid = (left+right)>>1;
//            if (nums[mid] < target) left = mid+1;
//            else if (nums[mid] > target) right = mid-1;
//            else return mid;
//        }
//        return -1;
//    }
//
//    int search(vector<int>& nums, int target) {
//        int pivot = find_pivot(nums)-1;
//        // cout << pivot << endl;
//
//        int in_left = b_search(nums, 0, pivot, target);
//        int in_right = b_search(nums, pivot+1, nums.size()-1, target);
//
//        if (in_left >= 0) return in_left;
//        return in_right;
//    }
//};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left+right) >> 1;
            if (nums[mid] == target) return mid;

            if (nums[mid] > nums[right]) {
                if (target>=nums[left] && target<nums[mid]) right = mid-1;
                else left = mid+1;
            } else if (nums[mid] < nums[left]) {
                if (target>nums[mid] && target<=nums[right]) left = mid+1;
                else right = mid-1;
            } else {
                if (target < nums[mid]) right = mid-1;
                else left = mid+1;
            }
        }
        return -1;
    }
};

int main()
{
    int a[] = {1, 3, 5};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.search(v, 1) << endl;
	return 0;
}
