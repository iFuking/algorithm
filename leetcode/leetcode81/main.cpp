#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int find_pivot_left(vector<int>& nums)
//    {
//        int left = 0, right = nums.size()-1;
//        while (left <= right) {
//            int mid = (left+right) >> 1;
//            if (nums[mid] > nums[right]) left = mid+1;
//            else if (nums[mid] < nums[right]) right = mid;
//            else --right;
//        }
//        return left;
//    }
//
//    bool b_search(vector<int>& nums, int left, int right, int target)
//    {
//        while (left <= right) {
//            int mid = (left+right) >> 1;
//            if (nums[mid] < target) left = mid+1;
//            else if (nums[mid] > target) right = mid-1;
//            else return true;
//        }
//        return false;
//    }
//
//    bool search(vector<int>& nums, int target) {
//        int pivot = find_pivot_left(nums);
//
//        bool in_left = b_search(nums, 0, pivot-1, target);
//        if (in_left) return true;
//        return b_search(nums, pivot, nums.size()-1, target);
//    }
//};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            while (left<right && nums[left]==nums[left+1]) ++left;
            while (left<right && nums[right]==nums[right-1]) --right;

            int mid = (left+right) >> 1;
            if (nums[mid] == target) return true;
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
        return false;
    }
};

int main()
{
	int a[] = {3, 1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution sol;
	cout << sol.search(v, 1) << endl;
	return 0;
}
