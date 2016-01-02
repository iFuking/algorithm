#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int vec_size = nums.size();
        for (int i = 0; i < vec_size; ++i) {
            if (nums[i] == 0) nums.push_back(0);
        }

        vector<int>::iterator iter = nums.begin();
        for (int i = 0; i < vec_size; ++i) {
            if (*iter == 0) iter = nums.erase(iter);
            else ++iter;
        }
        return;
    }
};

int main()
{
    int a[] = {0, 1, 0, 3, 12};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    sol.moveZeroes(v);
	return 0;
}
