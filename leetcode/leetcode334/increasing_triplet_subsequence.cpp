class Solution {
public:
    int b_search(vector<int> &v, int num) {
        int left = 0, right = v.size()-1;
        while (left <= right) {
            int mid = (left+right) >> 1;
            if (v[mid] < num) left = mid+1;
            else if (v[mid] > num) right = mid-1;
            else return mid;
        }
        return left;
    }

    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            int index = b_search(v, nums[i]);
            if (index == v.size()) {
                v.push_back(nums[i]);
                if (index == 2) return true;
                continue;
            }
            v[index] = nums[i];
        }
        return false;
    }
};